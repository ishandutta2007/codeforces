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

int cou = 0;
int sum = 0;

vector <pair <int, int> > a;

int n, k;
vector <int> p;

void perebor() {
    if (a.size() == k) {
        vector <int> b = p;
        ++cou;
        for (int i = 0; i < a.size(); ++i) {
            reverse(b.begin() + a[i].first, b.begin() + a[i].second + 1);
        }
        for (int i = 0; i < b.size(); ++i) {
            for (int j = i + 1; j < b.size(); ++j) {
                if (b[i] > b[j]) {
                    ++sum;
                }
            }
        }
        return;
    }
    for (int l = 0; l < n; ++l)
        for (int r = l; r < n; ++r) {
            a.push_back(mp(l, r));
            perebor();
            a.pop_back();
        }
}

void solve() {
    
    cin >> n >> k;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    perebor();

    cout << ld(sum) / ld(cou) << endl;
}