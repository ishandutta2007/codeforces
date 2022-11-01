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

bool comp(const vector <int> &a, const vector <int>& b) {
    return a.size() < b.size();
}

void solve() {
    int n;
    cin >> n;
    vector <int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    vector <vector <int>> cycles;

    vector <int> used(n, 0);

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int j = i;
            cycles.push_back(vector <int>());

            while (!used[j]) {
                used[j] = 1;
                cycles.back().push_back(j);
                j = p[j];
            }
        }
    }

    sort(cycles.begin(), cycles.end(), comp);

    
    if (cycles[0].size() > 2) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i < cycles.size(); ++i) {
        if (cycles[i].size() % cycles[0].size()) {
            cout << "NO" << endl;
            return;
        }
    }


    vector < pair <int, int> > g;
    
    cout << "YES\n";

    if (cycles[0].size() == 1) {
        for (int i = 0; i < n; ++i) {
            if (cycles[0][0] != i) {
                cout << i + 1 << " " << cycles[0][0] + 1 << "\n";
            }
        }
    }
    else {
        cout << cycles[0][0] + 1 << " " << cycles[0][1] + 1 << "\n";
        for (int i = 1; i < cycles.size(); ++i) {
            for (int j = 0; j < cycles[i].size(); ++j) {
                cout << cycles[i][j] + 1 << " " << cycles[0][j & 1] + 1 << "\n";
            }
        }
    }
}