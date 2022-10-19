#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e6+100;
int seg[N*4];
int lazy[N*4];
inline void shift(int nod){
    seg[nod*2]+=lazy[nod];
    seg[nod*2+1]+=lazy[nod];
    lazy[nod*2]+=lazy[nod];
    lazy[nod*2+1]+=lazy[nod];
    lazy[nod]=0;
    return ;
}
void upd(int nod,int l,int r,int L,int R,int val){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod]+=val;
        lazy[nod]+=val;
        return ;
    }
    int mid=(r+l)/2;
    shift(nod);
    upd(nod*2,l,mid,L,R,val);
    upd(nod*2+1,mid,r,L,R,val);
    seg[nod]=min(seg[nod*2],seg[nod*2+1]);
    return ;
}
int get(int nod,int l,int r){
    if (r-l==1) return l;
    shift(nod);
    ll mid=(r+l)/2;
    if (seg[nod*2]<=seg[nod*2+1]) return get(nod*2,l,mid);
    else return get(nod*2+1,mid,r);
}
int a[N];
int b[N];
int fen[N*2];
vector <int> ans[N];
int n;
int m;
void add(int idx,int val){
   // if (idx==0) cout << 1/0;
    for (;idx<n+m+1;idx+=idx & (-idx)) fen[idx]+=val;
}
int getfen(ll idx){
    int s=0;
    for (;idx;idx-=idx & (-idx)) s+=fen[idx];
    return s;
}
//map <int,int> mp;
inline int Main(){
   // cin >> n;
    //cin >> m;
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i=0;i<=n+m;i++) fen[i]=0;
    for (int i=0;i<=n;i++) ans[i].clear();
    for (int i=0;i<4*(n+1);i++){
        seg[i]=0;
        lazy[i]=0;
    }
    vector <pii> c;
    vector <int> s;
    ll jav=0;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s.pb(a[i]);
        c.pb({a[i],i});
    }
    sort(c.begin(),c.end());
    for (int i=1;i<=m;i++){
        //cin >> b[i];
        scanf("%d",&b[i]);
        s.pb(b[i]);
    }
    sort(b+1,b+m+1);
    for (int i=1;i<=n;i++){
        upd(1,0,n+1,i,n+1,-1);
    }
    ll mx=N;
    for (int i=m;i;i--){
        if (i!=m && b[i]==b[i+1]) {
            ans[mx].pb(b[i]);
            continue;
        }
        while(c.size() && c.back().F>b[i]){
            pii p=c.back();
            c.pop_back();
            upd(1,0,n+1,p.S,n+1,+2);
        }
        if (c.size()){
            for (int j=c.size()-1;j>-1;j--){
                if (c[j].F==b[i]){
                    upd(1,0,n+1,c[j].S,n+1,+1);
                }
                else break;
            }
        }
        int z=get(1,0,n+1);
        ans[z].pb(b[i]);
     //   cout << i << " " << z << " " << seg[1] << endl;
        if (z>mx) cout << 1/0;
        mx=z;
        while(c.size() && c.back().F>=b[i]){
            pii p=c.back();
            c.pop_back();
            upd(1,0,n+1,p.S,n+1,+1);
        }
    }
    sort(s.begin(),s.end());
    s.resize(unique(s.begin(),s.end())-s.begin());
    for (int i=0;i<=n;i++){
       if (i!=0) add(lower_bound(s.begin(),s.end(),a[i])-s.begin()+1,1);
        jav+=getfen(m+n)-getfen(lower_bound(s.begin(),s.end(),a[i])-s.begin()+1);
        reverse(ans[i].begin(),ans[i].end());
        for (auto u : ans[i]){
            ll v=lower_bound(s.begin(),s.end(),u)-s.begin()+1;
            jav+=getfen(n+m)-getfen(v);
            add(v,1);
        }
    }
    printf("%lld \n",jav);
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    //cin >> t;
    scanf("%d",&t);
    while(t--) Main();
}
/*
1
2 3
14 0
4 9 18
*/