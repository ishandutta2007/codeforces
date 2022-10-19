#include <bits/stdc++.h>
using namespace std;
int f[1000000+5],g[1000000+5];
const int MOD=1000000007;
int main(){
    int n;
    cin >> n;
    for (int i=0;i<=1000000;i++){
        f[i]=0;
        g[i]=0;
    }
    f[0]=1;g[0]=1;
    set <int> S;
    set <int> ::iterator  it;
    for (int i=1;i<=n;i++){
        S.clear();
        int x;
        cin >> x;
        int j;
        for ( j=1;j*j<x;j++){
            if (x%j==0){
                f[j]+=g[j-1];
                f[j]=f[j]%MOD;
                S.insert(j);
                f[x/j]+=g[x/j-1];
                f[x/j]=f[x/j]%MOD;
                S.insert(x/j);
            }
        }
        if (j*j==x) {f[j]+=g[j-1];f[j]=f[j]%MOD;S.insert(j);}
        for (it=S.begin();it!=S.end();it++){
            int u=*it;
            g[u]=f[u];
        }
    }
    int res=0;
    for (int i=1;i<=1000000;i++){
        res+=f[i];
        res=res%MOD;
    }
    cout << res;
}