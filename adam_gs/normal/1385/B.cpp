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
                int a[n];
                rep(i, n) a[i]=0;
                rep(i, 2*n) {
                        int b;
                        cin >> b;
                        ++a[b-1];
                        if(a[b-1]==1) cout << b << " ";
                }
                cout << '\n';
        }
}