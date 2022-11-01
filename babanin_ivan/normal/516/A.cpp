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

vector <int> g;

void solve() {
    g.resize(20);

    int n;

    vector <int> ans;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c <= '1') {
            continue;
        }
        int tmp = c - '0';
        if (tmp >= 7) {
            ans.push_back(7);
            if (tmp == 7) {
                continue;
            }

            if (tmp == 8) {
                for (int j = 0; j < 3; ++j) {
                    ans.push_back(2);
                }
            }
            else {
                ans.push_back(3);
                ans.push_back(3);
                ans.push_back(2);
            }
            continue;
        }

        if (tmp >= 5) {
            ans.push_back(5);
            if (tmp == 6) {
                ans.push_back(3);
            }

            continue;
        }

        if (tmp == 4) {
            for (int j = 0; j < 2; ++j) {
                ans.push_back(2);
            }
        }
        if (tmp >= 3) {
            ans.push_back(3);
        }
        else {
            ans.push_back(2);
        }
    }

    sort(ans.begin(), ans.end());

    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i];
    }
}