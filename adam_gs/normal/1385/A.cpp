#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                int x, y, z;
                cin >> x >> y >> z;
                if(x==y && x==z) {
                        cout << "YES\n" << x << " " << x << " " << x << '\n';
                } else if(x==y && x>z) {
                        cout << "YES\n" << x << " " << z << " " << z << '\n';
                } else if(x==z && x>y) {
                        cout << "YES\n" << x << " " << y << " " << y << '\n';
                } else if(y==z && y>x) {
                        cout << "YES\n" << x << " " << x << " " << y << '\n';
                } else cout << "NO\n";
        }
}