#include <iostream>
#include <vector>

#define M 100100

using namespace std;

long n,a[M],p[M],f=0,d[M],t[M],u[M];
vector<long> v[M];

void pre(void){
    for (long i=2; i<M; ++i)
    if (u[i]==0){
        p[f]=i;
        for (long j=i; j<M; j+=i)
        u[j]=f;
        ++f;
    }
}

void read(void){
    cin>>n;

    for (long i=0; i<n; ++i)
    cin>>a[i];

    for (long i=0; i<n; ++i){

        for (long j=0; p[j]*p[j]<=a[i]; ++j)
        if (a[i]%p[j]==0){
            v[i].push_back(p[j]);
            while (a[i]%p[j]==0)
            a[i]/=p[j];
        }
        if (a[i]>1)
        v[i].push_back(a[i]);

        long ans=1;

        for (int j=0; j<v[i].size(); ++j)
        ans=max(ans,(t[v[i][j]]+1));

        d[i]=ans;

        for (int j=0; j<v[i].size(); ++j)
        t[v[i][j]]=max(t[v[i][j]],ans);
    }


    long ans=0;
    for (int i=0; i<n; ++i)
    ans=max(d[i],ans);

    cout<<ans<<"\n";


}


int main()
{
    pre();
    read();
    return 0;
}