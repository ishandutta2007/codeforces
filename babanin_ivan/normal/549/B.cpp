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


int n;

vector <int> a;

vector <vector <int>> table;

vector <int> ans;

void run(vector <int> unused) {
    for (int i = 0; i < unused.size(); ++i) {
        if (a[unused[i]] == 0) {
            ans.push_back(unused[i]);
            for (int j = 0; j < n; ++j) {
                a[j] -= table[j][unused[i]];
            }

            unused.erase(unused.begin() + i);
            run(unused);
            return;
        }
    }
}

void solve() {
    cin >> n;
    a.resize(n);
    table.assign(n, vector <int> (n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;

            table[j][i] = c - '0';
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector <int> b;
    for (int i = 0; i < n; ++i) {
        b.push_back(i);
    }
    run(b);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << " ";;
    }
}