#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                int n, a=0;
                cin >> n;
                int v[n];
                rep(i, n) cin >> v[i];
                sort(v, v+n);
                rep(i, n-1) if(v[i+1]-v[i]>1) a=1;
                if(a==0) cout << "YES"; else cout << "NO";
                cout << '\n';
        }
}