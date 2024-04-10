#include <bits/stdc++.h>
#define maxn 2022
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 998244353 
#define debug(args...) printf(args)
using namespace std;

int n,k;
int w(int n){
    if(k == 1) return n;
    return (n*n+n)/2;
}

int dp[maxn][maxn];

int get(int m,int s){
    if(m == 0) return 1;
    int &r = dp[m][s];
    if(r+1) return r;
    r = get(m-1,s);
    if(w(m) <= s) r += get(m,s-w(m));
    r %= mod;
    return r;
}

int v[maxn];

int check(int sz){
    vector<int> a(sz);
    for(int i=0;i<sz;i++) a[i] = v[i];
    int s = 0;
    for(int i=0;i<k-1;i++){
        vector<int> b;
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        s = 0;
        for(int j=0;j<a.size();j++){
            s += a[j];
            if(s > n) return 0;
            for(int u=0;u<a[j];u++) b.pb(j+1);
        }
        a = b;
    }
    s = 0;
    for(int i=0;i<a.size();i++) s += a[i];
    return s <= n;
}

int ans;

void go(int pos){
    
    v[pos] = 1;
    
    while(check(pos+1)){
        ans++;
        go(pos+1);
        v[pos]++;
        if(pos && v[pos] > v[pos-1]) break;
    }
    
}

main(){
    scanf("%d%d",&n,&k);
    if(k <= 2){
        memset(dp,-1,sizeof(dp));
        printf("%d\n",(get(n,n)-1+mod)%mod);
        return 0;
    }
    go(0);
    printf("%d\n",ans);
}