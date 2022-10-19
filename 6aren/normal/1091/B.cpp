#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=200000+5;
const int MOD=998244353;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long resx=0, resy=0, n;
    cin >> n;
    for (int i=1; i<=2*n; i++){
        long long u, v;
        cin >> u >> v;
        resx+=u;
        resy+=v;
    }
    cout << resx/n << " " << resy/n;
    return 0;
}