#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int maxn = 1e5+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll seg[1200105];
//Simple Segment Tree

void modify(int o, int l, int r, int p, int val){
    if (l>p||r<p) return;
    if (l==r) {
        seg[o]=val;
        return;
    }
    int mid=(l+r)/2;
    modify(o*2+1, l, mid, p, val);
    modify(o*2+2, mid+1, r, p, val);
    seg[o]=min(seg[o*2+1],seg[o*2+2]);
}

ll query(int o, int l, int r, int L, int R){
    if (l>R||r<L) return iinf;
    if (l>=L&&r<=R) return seg[o];
    int mid=(l+r)/2;
    ll ql=query(o*2+1, l, mid, L, R);
    ll qr=query(o*2+2, mid+1, r, L, R);
    return min(ql, qr);
}


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        vector<int> a(n), b(n);
        vector<queue<int> > fat( n );

        REP(i,n) {
            cin>>a[i], a[i]--;
            modify(0, 0, n-1, i, a[i]);
            fat[a[i]].push(i);
        } // 0 - based
        REP(i,n) {
            cin>>b[i], b[i]--;

        }
        bool fg = 1;
        REP(i,n){
            if (!fat[b[i]].size()){
                cout<<"NO\n"; fg = 0; break;
            }
            int co = fat[b[i]].front(); fat[b[i]].pop();
            int mn = query(0, 0, n-1, 0, co);
            if (mn<a[co]) {
                cout<<"NO\n"; fg = 0; break;
            }
            modify(0,0,n-1, co, iinf);
        }
        if (!fg) continue;
        cout<<"YES\n";
    }


    
}