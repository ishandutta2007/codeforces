#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                int x, y, n;
                cin >> x >> y >> n;
                int k = n/x; k*=x; k+=y;
                if(k>n) k-=x;
                cout << k << '\n';
        }
}