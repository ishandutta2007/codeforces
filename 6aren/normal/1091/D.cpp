#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1000000+5;
const int MOD=998244353;

ll giaithua[N], giaithuanguoc[N], n;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    giaithua[0]=1;
    for (int i=1; i<=n; i++){
        giaithua[i]=(giaithua[i-1]*i)%MOD;
    }
    giaithuanguoc[n]=n;
    giaithuanguoc[n+1]=1;
    for (int i=n-1;i>=0; i--){
        giaithuanguoc[i]=(giaithuanguoc[i+1]*i)%MOD;
    }
    long long res=0;
    for (int i=0; i<=n; i++){
        long long plusi=(giaithuanguoc[n-i+1]*(giaithua[n-i]-1))%MOD;
        res=(res+plusi)%MOD;
    }
    res=(res+1)%MOD;
    cout << res;
    return 0;
}