#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=1e9+7;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
    x+=mod*(x<0);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
string a,x;
int n;
vector<vector<int> > c;
vector<vector<int> > dp;
int f(int nw,int cnt){
    if(nw==64){
        return 1;
    }
    cnt+=a[nw]-'0';
    if(cnt>2*n+10){
        cnt=2*n+10;
    }
    if(dp[nw][cnt]!=-1){
        return dp[nw][cnt];
    }
    dp[nw][cnt]=0;
    for(int i=(x[nw]-'0');i<=min(cnt,n);i+=2){
        add(dp[nw][cnt],mul(c[n][i],f(nw+1,2*(cnt-i))));
    }
    return dp[nw][cnt];
}
int main(){
    AquA;
    long long l,r,z;
    cin >> n >> l >> r >> z;
    c.resize(n+1,vector<int>(n+1));
    c[0][0]=1;
    for(int i=1;i<=n;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    dp.resize(64,vector<int>(3000,-1));
    l--;
    x=bitset<64>(z).to_string();
    a=bitset<64>(r).to_string();
    int ans=0;
    ans=f(0,0);
    fill(dp.begin(),dp.end(),vector<int>(3000,-1));
    a=bitset<64>(l).to_string();
    add(ans,-f(0,0));
    cout << ans << "\n";
    return 0;
}