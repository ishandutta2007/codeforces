#include <bits/stdc++.h>
using namespace std;

const int N=2005;
const int MOD=998244353;

int C[N][N], n, k, m;

int main(){
    cin >> n >> m >> k;
    C[0][0]=1;
    for (int i=1; i<=n; i++){
        C[0][i]=1;
        C[i][i]=1;
        for (int j=1; j<i; j++){
            C[j][i]=(C[j][i-1]+C[j-1][i-1])%MOD;
        }
    }
    long long res=(1LL*C[k][n-1]*m)%MOD;
    for (int i=1; i<=k; i++){
        res=(res*(m-1))%MOD;
    }
    cout << res;
}