#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const int INF=1e9+7;
int tr[256], N=1;
void upd(int v, int a) {
        v+=N; tr[v]=a; v/=2;
        while(v>0) { tr[v]=min(tr[2*v], tr[2*v+1]); v/=2; }
}
int cnt(int a, int b) {
        a+=N; b+=N;
        int wyn=min(tr[a], tr[b]);
        while(a/2!=b/2) {
                if(a%2==0) wyn=min(wyn, tr[a+1]);
                if(b%2==1) wyn=min(wyn, tr[b-1]);
                a/=2; b/=2;
        }
        return wyn;
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n, d;
        string x;
        cin >> n >> d >> x;
        while(N<n)N*=2;
        rep(i, n) tr[i+N]=INF;
        tr[N]=0;
        for(int i = N-1; i > 0; --i) tr[i]=min(tr[2*i], tr[2*i+1]);
        rep(i, n-1) {
                if(x[i+1]=='1') upd(i+1, cnt(max(i+1-d, 0), i)+1);
        }
        if(tr[N+n-1]<INF) cout << tr[N+n-1]; else cout << -1;
}