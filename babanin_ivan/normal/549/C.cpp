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

void print(int x) {
    string s[2];
    s[0] = "Daenerys";
    s[1] = "Stannis";
    if (x == 0) {
        cout << s[0] << "\n";
    }
    else {
        cout << s[1] << "\n";
    }
    exit(0);
}

void solve() {
    int n, k;
    cin >> n >> k;
    int t[2];
    t[0] = t[1] = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++t[x & 1];
    }

    if (n == k) {
        print(t[1] & 1);
    }

    int last = (n - k) & 1;

    if (last == 0) {
        if ((n - k) / 2 >= t[0] && (k & 1)) {
            print(!last);
        }
        if ((n - k) / 2 >= t[1]) {
            
        }
    }
    else {
        if ((n - k) / 2 >= t[0] && k % 2 == 0) {
            print(0);
        }
        if ((n - k) / 2 >= t[1]) {
            print(0);
        }
    }
    print(last);
}