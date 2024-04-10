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
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 1e6+5;

int tag[maxn*4], s[maxn*4];

void push(int o, int l, int r){
    if (!tag[o]) return;
    s[o]+=tag[o];
    if (l!=r){
        tag[o*2+1]+=tag[o];
        tag[o*2+2]+=tag[o];
    }
    tag[o]=0;
}

int query(int o, int l, int r, int L, int R){ // RMQ
    if (l>R||r<L) return 0;
    push(o,l,r);
    if (l>=L&&r<=R) return s[o];
    int mid = (l+r)/2;
    int ql = query(o*2+1,l,mid,L,R), qr = query(o*2+2,mid+1,r,L,R);
    return max(ql,qr);
}

void modify(int o, int l, int r, int L, int R, int v){
    push(o,l,r);
    if (l>R||r<L) return;
    if (l>=L&&r<=R) {
        tag[o]+=v; push(o,l,r); return;
    }
    int mid = (l+r)/2;
    modify(o*2+1,l,mid,L,R,v);
    modify(o*2+2,mid+1,r,L,R,v);
    s[o]=max(s[o*2+1],s[o*2+2]); 
}

void MO(int l, int r, int v){
    modify(0,0,1e6+1,l,r,v);
}

ll QU(int l, int r){
    return query(0,0,1e6+1,l,r);
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    vector<int> a(n), b(m);
    // BIT M (1e6+1);
    map<int, int> mp;
    REP(i,n){
        cin>>a[i];
        // mp[a[i]]++;
        MO(1,a[i], 1); // Rank Up
    }
    REP(i,m){
        cin>>b[i];
        MO(1,b[i],-1); // Covered
    }
    // debug(QU(8,8))<<'\n';
    int q; cin>>q;
    
    while (q--){
        int T; cin>>T;
        int i, to; cin>>i>>to;
        i--;
        if (T==1){
            MO(1,a[i], -1);
            // mp[a[i]] --; if (mp[a[i]]==1) mp.erase(a[i]);
            a[i] = to;
            MO(1,a[i],1);
            // mp[a[i]]++;
        }else{
            MO(1,b[i],1);
            b[i] = to;
            MO(1,b[i],-1);
        }
        int l = 1, r = 1e6+1;
        while (l!=r){
            int mid = (l+r)/2;
            if (QU(mid,1e6+1) > 0){
                l = mid+1;
            } else{
                r = mid;
            }
            // cout<<l<<' '<<r<<'\n';
        }
        if (l==1 && QU(1, 1e6+1)<=0){
            cout<<"-1"<<'\n'; continue;
        }
        if (QU(l-1, 1e6+1)>0){
            cout<<l-1<<'\n';
        }else cout<<l<<'\n';
        // assert(l>=2);
        // cout<<l-1<<'\n';
    }
    
}