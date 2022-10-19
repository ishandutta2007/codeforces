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
const int N=3e4+100;
ll seg[N*4][3][3];
ll dp[N];
ll mat[N];
ll a[N];
ll b[N];
ll iid[N];
ll solve(ll l,ll r){
    dp[l-1]=0;
    for (int i=l;i<=r;i++){
        dp[i]=(ll)-1e16;
    }
    for (int i=l;i<=r;i++){
        if (mat[i]!=i) dp[i]=max(dp[i],dp[i-1]+a[i]*b[i]);
        if (i>l && mat[i]!=i-1 && mat[i-1]!=i) dp[i]=max(dp[i],dp[i-2]+a[i]*b[i-1]+a[i-1]*b[i]);
        if (i>l+1){
            if (mat[i-1]!=i && mat[i-2]!=i-1 && mat[i]!=i-2){
                dp[i]=max(dp[i],dp[i-3]+a[i]*b[i-2]+a[i-1]*b[i]+a[i-2]*b[i-1]);
            }
            if (mat[i-1]!=i-1 && mat[i-2]!=i && mat[i]!=i-2){
                dp[i]=max(dp[i],dp[i-3]+a[i]*b[i-2]+a[i-1]*b[i-1]+a[i-2]*b[i]);
            }
            if (mat[i]!=i-1 && mat[i-1]!=i-2 && mat[i-2]!=i){
                dp[i]=max(dp[i],dp[i-3]+a[i]*b[i-1]+a[i-1]*b[i-2]+a[i-2]*b[i]);
            }
        }
    }
    return dp[r];
}
void build(ll nod,ll l,ll r){
    if (r-l==1){
        ll z=solve(l,r-1);
        seg[nod][0][0]=z;
        return ;
    }
    ll mid=(r+l)/2;
    build(nod*2,l,mid);
    build(nod*2+1,mid,r);
    if (r-l<=10){
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (i+j>r-l) continue;
                seg[nod][i][j]=solve(l+i,r-j-1);
            }
        }
    }
    else{
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                seg[nod][i][j]=max(seg[nod][i][j],seg[nod*2][i][0]+seg[nod*2+1][0][j]);
                ll z=solve(mid-1,mid);
                seg[nod][i][j]=max(seg[nod][i][j],seg[nod*2][i][1]+seg[nod*2+1][1][j]+z);
                z=solve(mid-2,mid);
                seg[nod][i][j]=max(seg[nod][i][j],seg[nod*2][i][2]+seg[nod*2+1][1][j]+z);
                z=solve(mid-1,mid+1);
                seg[nod][i][j]=max(seg[nod][i][j],seg[nod*2][i][1]+seg[nod*2+1][2][j]+z);
            }
        }
    }
}
void upd(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        mat[l]=val;
        solve(l,r-1);
        return ;
    }
    ll mid=(r+l)/2;
    if (mid>id) upd(nod*2,l,mid,id,val);
    else upd(nod*2+1,mid,r,id,val);
    memset(seg[nod],-31,sizeof seg[nod]);
    if (r-l<=10){
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (i+j>r-l) continue;
                seg[nod][i][j]=solve(l+i,r-j-1);
            }
        }
    }
    else{
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                seg[nod][i][j]=max(seg[nod][i][j],seg[nod*2][i][0]+seg[nod*2+1][0][j]);
                ll z=solve(mid-1,mid);
                seg[nod][i][j]=max(seg[nod][i][j],seg[nod*2][i][1]+seg[nod*2+1][1][j]+z);
                z=solve(mid-2,mid);
                seg[nod][i][j]=max(seg[nod][i][j],seg[nod*2][i][2]+seg[nod*2+1][1][j]+z);
                z=solve(mid-1,mid+1);
                seg[nod][i][j]=max(seg[nod][i][j],seg[nod*2][i][1]+seg[nod*2+1][2][j]+z);
            }
        }
    }
}
ll di[N];
int32_t main(){
    memset(seg,-31,sizeof seg);
    ll n,q;
    cin >> n >> q;
    vector <pii> aa,bb;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        aa.pb({x,i});
    }
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        bb.pb({x,i});
    }
    sort(aa.begin(),aa.end());
    sort(bb.begin(),bb.end());
    for (int i=0;i<n;i++){
        a[i+1]=aa[i].F;
        b[i+1]=bb[i].F;
        di[aa[i].S]=i+1;
        iid[bb[i].S]=i+1;
    }
    for (int i=0;i<n;i++){
        mat[i+1]=iid[aa[i].S];
    }
    for (int i=1;i<=n;i++){
      //  cout << a[i] << " " << b[mat[i]] << " " << i << " " << mat[i] << endl;
    }
   // cout << solve(1,n) << endl;
    build(1,1,n+1);
   // cout << seg[1][0][0] << endl;
    while(q--){
        ll x,y;
        cin >> x >> y;
        x=di[x],y=di[y];
        ll z=mat[x];
        upd(1,1,n+1,x,mat[y]);
        upd(1,1,n+1,y,z);
        cout << seg[1][0][0] << endl;
    }
}
/*
4 1
70 46 78 69
11 90 93 83
3 4
*/