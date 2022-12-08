#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 998244353
#define pi pair<int,int>
#define pl pair<ll,ll>
#define f first
#define s second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> ws(n);
        int l = 0;
        int r = n - 1;
        for(ll &w : ws) {
            cin >> w;
        }
        if(n == 1) {
            cout << "0\n";
            continue;
        }
        ll best = 0;
        ll curL = ws[0];
        ll curR = ws[n-1];
        while(l < r) {
            if(curL == curR) {
                best = l + n - r + 1;
                curL += ws[++l];
                curR += ws[--r];
                continue;
            }
            if(curL < curR) {
                curL += ws[++l];
            } else {
                curR += ws[--r];
            }
        }
        cout << best << "\n";
    }
    return 0;
}