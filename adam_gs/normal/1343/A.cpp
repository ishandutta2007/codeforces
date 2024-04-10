#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                int x, a=3;
                cin >> x;
                while(x%a!=0) a+=a+1;
                cout << x/a << '\n';
        }
}