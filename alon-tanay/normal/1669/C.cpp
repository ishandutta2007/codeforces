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
        vector<int> xs(n);
        for(int &x : xs) {
            cin >> x;
        }
        bool odd = xs[0]&1;
        bool fail = false;
        for(int i = 0; i < n; i += 2) {
            if(odd^(xs[i]&1)) {
                fail = true;
                break;
            }
        }
        odd = xs[1]&1;
        for(int i = 1; i < n; i += 2) {
            if(odd^(xs[i]&1)) {
                fail = true;
                break;
            }
        }
        cout << (fail ? "NO\n" : "YES\n");
    }
    return 0;
}