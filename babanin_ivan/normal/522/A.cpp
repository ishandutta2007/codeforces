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
    while (t--) {
        //++timer;
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

int n;

void normalize(string& s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = tolower(s[i]);
        }
    }
}

void solve() {
    cin >> n;

    map <string, int> lib;
    int k = 0;

    vector <pair <int, int> > input(n);

    for (int i = 0; i < n; ++i) {
        string tmp[3];
        for (int j = 0; j < 3; ++j) {
            cin >> tmp[j];
            normalize(tmp[j]);
            if (lib.find(tmp[j]) == lib.end()) {
                lib[tmp[j]] = k;
                ++k;
            }
        }
        
        input[i] = mp(lib[tmp[0]], lib[tmp[2]]);
    }

    vector <int> dp(k);

    for (int i = 0; i < n; ++i) {
        dp[input[i].first] = dp[input[i].second] + 1;
    }

    cout << (*max_element(dp.begin(), dp.end())) + 1 << endl;
}