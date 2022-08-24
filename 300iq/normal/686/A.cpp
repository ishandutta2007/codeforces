#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define ll long long
#define endl '\n'
#define fc first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, n) for(int i = 0; i < (int) (n); i++)

const int MOD = (int) 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif   
    int n;
    cin >> n;
    int sad = 0, x;
    ll cur = 0;
    cin >> cur;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c >> x;
        if (c == '+') {
            cur += x;
        } else {
            if (cur >= x) {
                cur -= x;
            } else {
                sad++;
            }
        }
    }
    cout << cur << " " << sad << endl;
}