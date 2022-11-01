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

const int mod = 1000000007;

string s, t;

vector <int> good;

void get() {
    string tmp = t + "#" + s;
    vector <int> pi(tmp.size());

    for (int i = 1; i < tmp.size(); ++i) {
        int j = pi[i - 1];
        while (j > 0 && tmp[i] != tmp[j]) {
            j = pi[j - 1];
        }
        if (tmp[i] == tmp[j]) {
            ++j;
        }
        pi[i] = j;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (pi[t.size() + 1 + i] == t.size()) {
            good[i] = true;
        }
    }
}

void solve() {
    cin >> s >> t;
    good.resize(s.size());
    get();

    vector <li> dp1(s.size() + 1);
    vector <li> dp2(s.size() + 1);
    vector <li> pref(s.size() + 1);
    li cur = 0;
    li sumall = 0;

    int last = -1;

    for (int i = 1; i <= s.size(); ++i) {
        
        dp2[i] = dp2[i - 1];
        
        if (good[i - 1]) {
            int pos = i - t.size();
            if (last == -1) {
                dp2[i] = (dp2[i] + dp1[pos] + (pos + 1)) % mod;
            }
            else {
                int pos2 = last - t.size();
                dp2[i] = (dp2[i] + dp1[pos] - dp1[pos2]/* - (pref[pos2] * (pos - pos2)) % mod*/ + mod + (pos - pos2)) % mod;
            }

            last = i;
        }

        sumall = (sumall + dp2[i]) % mod;
        dp1[i] = (dp1[i - 1] + sumall) % mod;
        pref[i] = (pref[i - 1] + dp2[i]) % mod;

        cur = (cur + dp2[i]) % mod;
    }

    cout << cur << endl;
}