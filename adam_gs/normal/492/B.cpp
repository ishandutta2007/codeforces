#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n, l;
        cin >> n >> l;
        int t[n];
        rep(i, n) cin >> t[i];
        sort(t, t+n);
        int ma=max(t[0], l-t[n-1]);
        ma*=2;
        rep(i, n-1) {
                int p = t[i+1]-t[i];
                ma=max(ma, p);
        }
        cout << ma/2;
        if(ma%2==1) cout << ".5";
}