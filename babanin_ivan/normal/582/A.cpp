#pragma comment (linker, "/STACK:128000000")
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

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout); 
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;

    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }
    return gcd(y, x % y);

}
void solve() {
    int n;
    cin >> n;
    vector <int> a;
    

    set <int> t;
    map <int, int> num;

    for (int i = 0; i < n *n; ++i) {
        int x;
        cin >> x;
        t.insert(x);
        num[x]++;
        a.push_back(x);
    }

    sort(a.begin(), a.end());
    
    int i = 0;
    vector <int> res;
    /*
    for (int i = 0; i < a.size();) {
        int j = i;
        while (j < a.size() && a[i] == a[j]) {
            ++j;
        }
        if ((j - i) & 1) {
            res.push_back(a[i]);
        }
        i = j;
    }
    */

    while (!t.empty()) {
        int x = *t.rbegin();
        if (num[x] == 0) {
            t.erase(x);
            continue;
        }
        res.push_back(x);
        ++num[x];
        for (int u = 0; u < res.size(); ++u) {
            int v = gcd(x, res[u]);
            --num[v];
            --num[v];
            if (num[v] < 0) {
                assert(false);
            }
        }
    }

    for (int y : res) {
        cout << y << " ";
    }
}