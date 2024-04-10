#include <iostream> 
#include <cstdio> 
#include <fstream>
#include <functional>
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
#include <deque>
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back
#define y1 botva
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
    //cerr << NAME << endl;
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    clock_t start = clock();
#else 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
#endif 
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(10);
    int t = 1;
    //cin >> t;  
    for (int i = 1; i <= t; ++i) {
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA 
    //cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
    return 0;
}

int n;


struct eve {
    int left, right;
    int id;
    eve(){}
    eve(int left, int right, int id):left(left), right(right), id(id) {
    }
    bool operator < (const eve& oth)  const {
        return left > oth.left || (left == oth.left && right > oth.right);
    }
};


vector <int> p;
vector <int> l;
int q;
vector <eve> eves;
vector <int> ans;

struct hr {
    int x;
    int maxx;
    int sum;

    hr(int x, int maxx, int sum) :x(x), maxx(maxx), sum(sum){}
};

vector <hr> ttt;

void solve() {
    cin >> n;

    /*par.resize(n);
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }*/

    p.resize(n);
    l.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> l[i];
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        eves.push_back(eve(l, r, i));
    }
    sort(eves.begin(), eves.end());

    ans.resize(q);
    
    int cur = n - 1;
    ttt.push_back(hr(p[n - 1], p[n - 1] + l[n - 1], 0));

    for (int i = 0; i < eves.size(); ++i) {

        while (cur > eves[i].left) {
            --cur;
            hr tmp = hr(p[cur], p[cur] + l[cur], 0);
            while (ttt.size() && tmp.maxx >= ttt.back().x) {
                tmp = hr(tmp.x, max(tmp.maxx, ttt.back().maxx), 0);
                ttt.pop_back();
            }

            ttt.push_back(tmp);
            if (ttt.size() > 1) {
                ttt.back().sum = ttt[ttt.size() - 2].sum + (ttt[ttt.size() - 2].x - tmp.maxx);
            }
        }

        if (ttt.back().maxx >= p[eves[i].right]) {
            continue;
        }

        /*int l = ttt.size() - 1;
        int r = 0;

        while (l - r > 2) {
            int m = (l + r) / 2;
            if (ttt[m].maxx < p[eves[i].right]) {
                l = m;
            }
            else {
                r = m;
            }
        }
        for (int j = r; j <= l; ++j) {
            if (ttt[j].maxx < p[eves[i].right]) {
                int id = eves[i].id;
                ans[id] = ttt.back().sum - ttt[j].sum;
            }
        }
        */
        int l = 0;
        int r = ttt.size() - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (ttt[m].maxx < p[eves[i].right]) {
                r = m;
            }
            else {
                l = m;
            }
        }
        int id = eves[i].id;
        ans[id] = ttt.back().sum - ttt[r - 1].sum;
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << "\n";
    }
}