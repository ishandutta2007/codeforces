//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1e5, INF = 1e9;

int n, m;
vector<int> heA, heP, meA;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s; int x; cin >> s >> x;
        if(s[0] == 'A') heA.push_back(x);
        else heP.push_back(x);
    }
    meA.resize(m);
    for(int i = 0; i < m; i++) cin >> meA[i];
    sort(all(meA));
    sort(all(heA));
    sort(all(heP));
    int ans = 0;

    for(int x = 1; x <= min(m, sz(heA)); x++) {
        bool ok = true;
        int cur = 0;
        for(int i = 0; i < x; i++) {
            ok &= (meA[m - i - 1] >= heA[x - i - 1]);
            cur +=  meA[m - i - 1] - heA[x - i - 1];
        }
        if(ok) ans = max(ans, cur);
    }

    if(m > n) {
        vector<bool> ban(m, false);
        bool ok = true;
        for(int i = 0; i < sz(heP); i++) {
            bool done = false;
            for(int j = 0; j < m; j++)
                if(!ban[j] && meA[j] > heP[i]) {
                    done = true;
                    ban[j] = true;
                    break;
                }
            if(!done) ok = false;
        }
        if(ok) {
            vector<int> meA1;
            for(int i = 0; i < m; i++) if(!ban[i]) meA1.push_back(meA[i]);
            for(int i = 0; i < sz(heA); i++) ok &= (meA1[sz(meA1) - i - 1] >= heA[sz(heA) - i - 1]);
            if(ok) {
                int cur = 0;
                for(int x : meA1) cur += x;
                for(int x : heA) cur -= x;
                ans = max(ans, cur);
            }
        }
    }

    cout << ans;
}