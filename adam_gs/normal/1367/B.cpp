#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                int n;
                cin >> n;
                int a[n], l=0, b=0;
                rep(i, n) {
                        cin >> a[i];
                        if(a[i]%2==1) { ++l; if(i%2==0) ++b; }
                }
                if(l==n/2) cout << b; else cout << -1;
                cout << '\n';
        }
}