#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>
#define f first
#define s second
#define vi vector<int>
#define vl vector<ll>
#define ld long double

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll n,m,k;
        cin >> n >> m >> k;
        k -= 2;
        bool ans = (k >= 0);
        if(m > (n*(n-1))/2) {
            ans = false;
        }
        if(m + 1 < n) {
            ans = false;
        }
        if(k == 0 && n != 1) {
            ans = false;
        }
        if(k == 1 && m < (n*(n-1))/2) {
            ans = false;
        }
        cout << (ans ? "YES\n":"NO\n");
    }
    return 0;
}