#include <iostream>
#include <algorithm>
#include <vector>

#define f first
#define s second
#define M 200200
#define N 1500
#define mp make_pair

using namespace std;

pair <long, long> p[M];
vector<long> l(N,0),r(N,0);
vector<bool> b(N,0);

int main()
{
    long n,k,c,u=0,t,ans=0,ls,rs;

    cin>>n;

    for (long i=1; i<=n; ++i){
        cin>>k;
        for (long j=0; j<k; ++j){
            cin>>c;
            p[u++]=mp(c,i);
        }
    }
    sort(p,p+u);

    for (long i=0; i<u; ++i){
        t=p[i].s;
        if (b[t] && l[t]!=r[t])
        ans++;
        b[t]=1;
        l[t]=0;
        r[t]=0;
        ls=t-1;
        rs=t+1;
        if (ls==0)
        ls=n;
        if (rs==n+1)
        rs=1;
        r[ls]++;
        l[rs]++;
    }

    cout<<ans;

    return 0;
}