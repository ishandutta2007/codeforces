#include <bits/stdc++.h>

using namespace std;

long long n, ki, s, mb, k;
const long long B=10000;
vector<long long> a, sa;
long long l[1501], r[1501], t[1501][1501], v[1501][1501];
map<long long, long long> m;
vector<long long> b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s >> mb >> k;
    for(int i=0;i<n;i++) {
        long long be;
        cin >> be;
        a.push_back(be);
        sa.push_back(be);
    }
    for(int i=0;i<=n;i++) {
        l[i]=B;
    }
    for(int i=0;i<s;i++) {
        long long be1, be2;
        cin >> be1 >> be2;
        if(l[be2]>be1) l[be2]=be1;
    }
    for(int i=n-1;i>=0;i--) {
        if(l[i+1]<l[i]) l[i]=l[i+1];
    }
    sort(sa.begin(),sa.end());
    for(int i=0;i<n;i++) {
        m[sa[i]]=i;
    }
    for(int i=0;i<n;i++) {
        a[i]=m[a[i]];
    }
    for(int i=0;i<=n;i++) {
        t[i][0]=0;
        for(int j=1;j<=n;j++) {
            t[i][j]=t[i][j-1];
            if(a[j-1]<=i) t[i][j]++;
        }
    }
    int x=0, y=n, z;
    while(x<y) {
        z=(x+y)/2;
        for(int j=1;j<=n;j++) v[0][j]=0;
        for(int i=1;i<=mb;i++) {
            v[i][0]=0;
            for(int j=1;j<=n;j++) {
                v[i][j]=v[i][j-1];
                if(l[j]==B) continue;
                long long most=v[i-1][l[j]-1]+t[z][j]-t[z][l[j]-1];
                if(most>v[i][j]) v[i][j]=most;
            }
        }
        if(v[mb][n]>=k) y=z;
        else x=z+1;
    }
    sa.push_back(-1);
    cout << sa[x] << endl;
    return 0;
}