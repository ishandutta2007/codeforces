#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                int a, b;
                cin >> a >> b;
                if(a>b) swap(a, b);
                cout << max(2*a, b)*max(2*a, b) << '\n';
        }
}