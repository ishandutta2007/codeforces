#include <bits/stdc++.h>

#define INF INT_MAX
#define ll long long
#define endl '\n'
#define fc first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

int p[255];

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif   

    for (int i = '0'; i <= '9'; i++) {
        p[i] = i - '0';
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        p[c] = c - 'A' + 10;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        p[c] = c - 'a' + 36;
    }
    p['-'] = 62;
    p['_'] = 63;
    ll ans = 1;
    string s;
    cin >> s;
    for (int i = 0; i < (int) s.size(); i++) {
        int cnt = 0;
        for (int a = 0; a < 64; a++) {
            for (int b = 0; b < 64; b++) {
                if ((a & b) == p[s[i]]) {
                    cnt++;
                }
            }
        }
        ans *= cnt;
        ans %= 1000000007;
    }
    cout << ans << endl;
}