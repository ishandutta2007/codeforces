#include<bits/stdc++.h>
using namespace std;
#define rep(a,b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        b=min(b,m*a);
        int ans=n/m*b;
        n-=m*(n/m);
        ans+=min(n*a, b);
        cout << ans;
}