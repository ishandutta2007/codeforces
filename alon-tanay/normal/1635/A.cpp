#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        ll mn = 0;
        for(int i = 0; i < n; i ++) {
            ll x;
            cin >> x;
            mn |= x;
        }
        cout << mn << "\n";
    }

    return 0;
}