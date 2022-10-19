#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n, m;
        cin >> n >> m;
        long long p = 1, ans=0;
        rep(i, m) {
                long long a;
                cin >> a;
                if(a>=p) ans+=a-p; else ans+=a+n-p;
                p=a;
        }
        cout << ans;
}