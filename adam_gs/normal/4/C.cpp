#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
map<string,int>m;
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n;
        cin >> n;
        rep(i, n) {
                string x;
                cin >> x;
                ++m[x];
                if(m[x]==1) cout << "OK"; else cout << x << m[x]-1;
                cout << '\n';
        }
}