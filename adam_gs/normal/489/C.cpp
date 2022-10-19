#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int t[107];
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n, m;
        cin >> n >> m;
        if(n==1 && m==0) { cout << "0 0"; return 0; }
        if(m==0) { cout << "-1 -1"; return 0; }
        int s=m;
        t[0]=1; --s;
        for(int i = n-1; i > 0; --i) { t[i]=min(9, s); s-=min(9, s); }
        if(s>8) { cout << "-1 -1"; } else {
                t[0]+=s;
                rep(i, n) cout << t[i];
                cout << " ";
                rep(i, n) { cout << min(9, m); m-=min(9, m); }
        }
}