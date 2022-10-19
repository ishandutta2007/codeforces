#include <bits/stdc++.h>
typedef  int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=5e5+100,inf=(ll)1e9;
const int lg=20;
int rnk[lg][N];
int n, pw, P[N], ptr;
string S;
bool cmp(int i, int j){
    if (rnk[pw - 1][i] != rnk[pw - 1][j])
        return rnk[pw - 1][i] < rnk[pw - 1][j];
    if (max(i, j) + (1 << (pw - 1)) > n){
        return i > j;
    }
    return rnk[pw - 1][(1 << (pw - 1)) + i] < rnk[pw - 1][(1 << (pw - 1)) + j];
}
void suffix_array(){
    for (int i = 1; i <= n; ++ i){
        rnk[0][i] = S[i - 1] - 'a', P[i] = i;
    }
    for (pw = 1; pw < lg; ++ pw){
        sort(P + 1, P + n + 1, cmp);
        rnk[pw][P[1]] = 1;
        for (int i = 2; i <= n; ++ i){
            rnk[pw][P[i]] = rnk[pw][P[i - 1]] + cmp(P[i - 1], P[i]);
        }
    }
}
int LCP(int x, int y){
    int res = 0;
    for (int i = lg - 1; i >= 0; -- i){
        if (rnk[i][x] != rnk[i][y] || max(x, y) + (1 << i) - 1 > n)
            continue;
        x += 1 << i , y += 1 << i;
        res |= (1 << i);
    }
    return res;
}
ll where[N];
ll dp[N];
struct node{
    int min=1e9;
    int max=0;
};
node seg[N*4];
void build(ll nod,ll l,ll r){
    if (r-l==1){
        if (l==n) seg[nod].min=-1e9;
        else seg[nod].min=LCP(P[l],P[l+1]);
        return ;
    }
    ll mid=(r+l)/2;
    build(nod*2,l,mid);
    build(nod*2+1,mid,r);
    seg[nod].min=min(seg[nod*2].min,seg[nod*2+1].min);
}
ll getmin(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return inf;
    if (l>=L && r<=R) return seg[nod].min;
    ll mid=(r+l)/2;
    return min(getmin(nod*2,l,mid,L,R),getmin(nod*2+1,mid,r,L,R));
}
/*
ll getr(ll L,ll val){
    ll l=l-1,r=n;
    while(r-l>1){
        ll mid=(r+l)/2;
        if (getmin(1,1,n+1,L,mid+1)>=val) l=mid;
        else r=mid;
    }
    return r;
}
*/
ll getr(ll nod,ll l,ll r,ll L,ll val){

    if (r<=L) return n;
    ll mid=(r+l)/2;
    if (l>=L){
        if (seg[nod].min>=val) return n;
        else {
            if (r-l==1){
            //    cout << "KIR " << l << " " << L << " " << val << endl;
                return l;
            }
            ll x=getr(nod*2,l,mid,L,val);
            if (x<n) return x;
            else{
                x=getr(nod*2+1,mid,r,L,val);
                return x;
            }
        }
    }
    return min(getr(nod*2,l,mid,L,val),getr(nod*2+1,mid,r,L,val));
}
/*
ll getl(ll L,ll val){
    ll l=0,r=L;
    while(r-l>1){
        ll mid=(r+l)/2;
        if (getmin(1,1,n+1,mid,L)>=val) r=mid;
        else l=mid;
    }
    return r;
}
*/
ll getl(ll nod,ll l,ll r,ll L,ll val){
    if (l>=L) return 1;
    ll mid=(r+l)/2;
    if (r<=L){
        if (seg[nod].min>=val) return 1;
        else{
            if (r-l==1){
                return l+1;
            }
            if (seg[nod*2+1].min>=val){
                return getl(nod*2,l,mid,L,val);
            }
            else return getl(nod*2+1,mid,r,L,val);
        }
    }
    return max(getl(nod*2,l,mid,L,val),getl(nod*2+1,mid,r,L,val));
}
void upd(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        seg[nod].max=val;
        return ;
    }
    ll mid=(r+l)/2;
    if (mid>id) upd(nod*2,l,mid,id,val);
    else upd(nod*2+1,mid,r,id,val);
    seg[nod].max=max(seg[nod*2].max,seg[nod*2+1].max);
}
ll get(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return 0;
    if (l>=L && r<=R) return seg[nod].max;
    ll mid=(r+l)/2;
    return max(get(nod*2,l,mid,L,R),get(nod*2+1,mid,r,L,R));
}
int32_t main(){
    sync;
    cin >> n;
    cin >> S;
    if (n==1) kill(1);
    suffix_array();
    for (int i=1;i<=n;i++){
        where[P[i]]=i;
    }
    build(1,1,n+1);
    dp[n]=1;
    dp[n-1]=1;
    upd(1,1,n+1,where[n],1);
   // upd(1,1,n+1,where[n-1],1);
    ll R=n-1;
    for (int i=1;i<=n;i++){
   //     cout << P[i] << " ";
    }
  // cout << endl; 
   // cout << LCP(P[1],P[2]) << endl;
    for (int i=n-2;i;i--){
        dp[i]=dp[i+1]+1;
        ll z=dp[i+1];
        while(dp[i]>1){
            ll l=getl(1,1,n+1,where[i],dp[i]-1);
            ll r=getr(1,1,n+1,where[i],dp[i]-1);
        //    cout << i << " " << dp[i] << " " << l << " " << r << endl;
            ll x=getl(1,1,n+1,where[i+1],dp[i]-1);
            ll y=getr(1,1,n+1,where[i+1],dp[i]-1);
        //    cout << i << " " << dp[i] << " " << x << " " << y << " " << getmin(1,1,n+1,4,5) << endl;
            if (get(1,1,n+1,l,r+1)>=dp[i]-1 || get(1,1,n+1,x,y+1)>=dp[i]-1){
                break;
            }
            dp[i]--;
            upd(1,1,n+1,where[R],dp[R]);
            R--;
        }
     //   cout << i << " kwjefib " << dp[i] << endl;
    }
    ll mx=1;
    for (int i=1;i<=n;i++){
        mx=max(mx,dp[i]);
    }
    cout << mx << endl;
}