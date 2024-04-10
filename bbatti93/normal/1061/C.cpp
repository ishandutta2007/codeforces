#include <bits/stdc++.h>

using namespace std;

const long long N=100000, M=1000000, MOD=1000000007ll;
long long n, a;
vector<int> ti[M+1], d[N+2], v[N+2];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a;
        ti[a].push_back(i);
    }
    for(int i=1;i<=n;i++) {
        d[i].push_back(-1);
        for(int j=i;j<=M;j+=i) {
            for(int k=0;k<ti[j].size();k++) {
                d[i].push_back(ti[j][k]);
            }
        }
        d[i].push_back(n);
        sort(d[i].begin(),d[i].end());
    }
    d[n+1].push_back(-1);
    d[n+1].push_back(n);
    v[n+1].push_back(0);
    v[n+1].push_back(0);
    for(int i=n;i>0;i--) {
        v[i].resize(d[i].size());
        long long k=(int)v[i+1].size()-1;
        v[i][0]=v[i].back()=0;
        for(int j=(int)d[i].size()-2; j>0;j--) {
            while(d[i+1][k-1]>d[i][j]) k--;
            v[i][j]=(1+v[i][j+1]+v[i+1][k])%MOD;
        }
    }
    cout << v[1][1] << endl;
    return 0;
}