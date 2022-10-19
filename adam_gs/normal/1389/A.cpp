#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                int a, b;
                cin >> b >> a;
                a/=2;
                if(a<b) cout << "-1 -1\n"; else cout << a << " " << 2*a << '\n';
        }
}