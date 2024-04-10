#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int t[30007];
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n, m;
        cin >> n >> m;
        rep(i, n-1) cin >> t[i+1];
        int i = 1;
        while(i<m) i+=t[i];
        if(i==m) cout << "YES"; else cout << "NO";
}