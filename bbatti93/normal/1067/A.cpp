#include <bits/stdc++.h>

using namespace std;
const long long M=998244353ll;
long long n, k, ki;
int t[100001], s[100001][201], u[100001][201], as[100001], au[100001], ks[100001][201], ku[100001][201];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> t[i];
    }
    as[0]=1;
    for(int i=0;i<=200;i++) ks[0][i]=1;
    for(int i=1;i<=n;i++) {
        if(t[i]==-1) for(int j=1;j<=200;j++) {
            s[i][j]=(as[i-1]-ks[i-1][j-1]+u[i-1][j]+M)%M;
            u[i][j]=(ks[i-1][j-1]+ku[i-1][j-1])%M;
        } else {
            int j=t[i];
            s[i][j]=(as[i-1]-ks[i-1][j-1]+u[i-1][j]+M)%M;
            u[i][j]=(ks[i-1][j-1]+ku[i-1][j-1])%M;
       }
        for(int j=1;j<=200;j++) {
            ks[i][j]=(ks[i][j-1]+s[i][j])%M;
            ku[i][j]=(ku[i][j-1]+u[i][j])%M;
        }
        as[i]=ks[i][200];
    }
    cout << as[n] << "\n";
    return 0;
}