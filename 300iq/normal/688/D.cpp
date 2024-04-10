#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define endl '\n'
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int u, v;
const int MAXN = (int) 1e6 + 7;
int lp[MAXN];
int used[MAXN];
vector <int> p;
vector <int> govno;

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            int cur = 1;
            while (k % i == 0) {
                cur *= i;
                k /= i;
            }
            govno.pb(cur);
        }
    }
    if (k != 1) {
        govno.pb(k);
    }
    vector <int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        forn (j, govno.size()) {
            if (c[i] % govno[j] == 0) {
                used[j] = 1;
            }
        }
    }
    bool good = 1;
    forn (j, govno.size()) {
        good &= used[j];
    }
    cout << (good ? "Yes" : "No") << endl;
}