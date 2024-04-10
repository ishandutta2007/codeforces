#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=200000+5;
const int MOD=998244353;

long long res[N];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, cnt=0, k;
    cin >> n;
    for (int i=1; i*i<n; i++){
        k=i;
        if (n%i) continue;
        int u=n/i;
        res[cnt]=u+1LL*i*u*(u-1)/2;
        cnt++;
        res[cnt]=i+1LL*u*i*(i-1)/2;
        cnt++;
    }
    k++;
    if (k*k==n){
        res[cnt]=k+1LL*k*k*(k-1)/2;
        cnt++;
    }
    sort(res, res+cnt);
    for (int i=0; i<cnt; i++){
        cout << res[i] << " ";
    }
}