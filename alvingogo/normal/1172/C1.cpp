#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;
 
const int mod=998244353;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int po(int x,int y){
    int z=1;
    while(y){
        if(y&1){
            z=mul(z,x);
        }
        x=mul(x,x);
        y>>=1;
    }
    return z;
}
int inv(int x){
    return po(x,mod-2);
}
vector<int> fra;
void init(int x){
    fra.resize(x);
    fra[0]=1;
    for(int i=1;i<x;i++){
        fra[i]=mul(fra[i-1],i);
    }
}
int main(){
    AquA;
    init(6029);
    int n,m;
    cin >> n >> m;
    vector<int> v(n),w(n);
    for(int i=0;i<n;i++){
        cin >> w[i];
    }
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int b=0,c=0;
    for(int i=0;i<n;i++){
        if(w[i]==0){
            b+=v[i];
        }
        else{
            c+=v[i];
        }
    }
    int d=b+c;
    vector<vector<int> > dp(m+1,vector<int>(m+1));
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(dp[i][j]){
                int good=c+j,all=d+j-(i-j),bad=all-good;
                if(all<0 || bad<0){
                    continue;
                }
                add(dp[i+1][j],mul(dp[i][j],mul(1,inv(all))));
                add(dp[i+1][j+1],mul(dp[i][j],mul(1,inv(all))));
            }
        }
    }
    vector<vector<int> > C(m+1,vector<int>(m+1));
    C[0][0]=1;
    for(int i=1;i<=m;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j];
            add(C[i][j],C[i-1][j-1]);
        }
    }
    int f=0,g=0;
    vector<int> pi(m+1),pl(m+1),gi(m+1),gl(m+1);
    pi[0]=1;
    pl[0]=1;
    gi[0]=gl[0]=1;
    for(int i=1;i<=m;i++){
        pi[i]=mul(pi[i-1],c+i-1);
        pl[i]=mul(pl[i-1],b-i+1);
        gi[i]=mul(gi[i-1],c+i-2);
        gl[i]=mul(gl[i-1],b-i);
    }
    for(int i=0;i<=m;i++){
        for(int j=i;j<=m;j++){
            add(f,mul(1+i,mul(mul(fra[i],mul(C[j][i],gi[j-i])),mul(dp[m][j],pl[m-j]))));
            if(j<=b){
                add(g,mul(max(1-i,0),mul(mul(fra[i],mul(C[j][i],gl[j-i])),mul(dp[m][m-j],pi[m-j]))));
            }
        }
    }
    //g=(mod-g)%mod;
    for(int i=0;i<n;i++){
        if(w[i]==0){
            cout << mul(g,v[i]) << '\n';
        }
        else{
            cout << mul(f,v[i]) << '\n';
        }
    }
    return 0;
}