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
const int N=1e5+100;
string e[5];
ll t[32][32];
ll seg[4*N][32];
ll tar(ll x,ll y){
    string s=e[x]+e[y];
    ll ans=0;
    for (int i=0;i<5;i++){
        string a=s;
        string b=e[i];
        while(a.size() && b.size()){
            if (a.back()==b.back()){
                a.pop_back();
                b.pop_back();
            }
            else a.pop_back();
        }
        if (b.size()==0){
            ans+=(1<<i);
        }
    }
    string a=s,b="abc";
    while(a.size() && b.size()){
        if (a.back()==b.back()){
            a.pop_back();
            b.pop_back();
        }
        else a.pop_back();
    }
    if (b.size()==0){
        ans-=1000000;
    }
    return ans;
}
void upd(ll nod,ll l,ll r,ll id,char c){
    if (r-l==1){
        for (int i=1;i<32;i++){
            seg[nod][i]=1;
        }
        seg[nod][0]=N;
        seg[nod][(1<<((ll) (c-'a')))]=0;

        return ;
    }
    ll mid=(r+l)/2;
    if (mid>id) upd(nod*2,l,mid,id,c);
    else upd(nod*2+1,mid,r,id,c);
    for (int i=0;i<32;i++) seg[nod][i]=N;
  //  cout << " e9r8gj9ergu3rhtogjortgnn " << seg[nod][11] << endl;
    for (int i=0;i<32;i++){
        for (int j=0;j<32;j++){

            if (t[i][j]>=0) seg[nod][t[i][j]]=min(seg[nod][t[i][j]],seg[nod*2][i]+seg[nod*2+1][j]);
        }
    }
   // cout << " kerhfuehrgofjh " << seg[nod][11] << endl;
    return ;
}
int32_t main(){
    sync;
    e[0]="a";
    e[1]="b";
    e[2]="c";
    e[3]="ab";
    e[4]="bc";
    for (int i=0;i<32;i++){
        for (int j=0;j<32;j++){
            ll p1=0;
            if (i==0 || j==0){
                t[i][j]=i+j;
                continue;
            }
            for (int k=0;k<5;k++){
                for (int x=0;x<5;x++){
                    if (p1<0) break;
                    if ((i & (1<<k)) && (j & (1<<x))) {
                        if (tar(k,x)<0){
                            p1=-1000;
                            break;
                        }
                        else p1 |= tar(k,x);
                    }
                }
            }
            t[i][j]=p1;


        }
    }
    ll n;
    cin >> n ;
    ll d;
    cin >> d;
    for (int i=1;i<=n;i++){
        char c;
        cin >> c;
        upd(1,1,n+1,i,c);
    }
    while(d--){
        ll x;
        cin >> x;
        char c;
        cin >> c;
        upd(1,1,n+1,x,c);
        ll ans=N;
        for (int i=0;i<32;i++) {
            ans=min(ans,seg[1][i]);

        }
        cout << ans << endl;
    }
}