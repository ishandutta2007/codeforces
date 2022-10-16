#include <iostream>
#include <algorithm>

using namespace std;

struct elem
{
    long long int cost;
    long long int monit;
    long long int masca;
}v[105];

bool operator<(const elem &a,const elem &b)
{
    if(a.monit<b.monit)
        return 1;
    return 0;
}

#define inf 8000000000000000000ll
long long int din[1048605];
//long long int prev[1048605];

int main()
{
    long long int m,n,b,i,aux,j,t;
    cin>>m>>n>>b;

    for(i=1;i<=m;i++)
    {
        cin>>v[i].cost>>v[i].monit>>aux;

        for(j=0;j<aux;j++)
        {
            cin>>t;
            v[i].masca|=(1<<(t-1));
        }
    }

    sort(v+1,v+m+1);
    din[0]=0;

    for(i=1;i<(1<<n);i++)
        din[i]=inf;

    long long int monitoare;
    long long int rasp=inf;

    for(i=1;i<=m;i++)
    {
        monitoare=b*v[i].monit;
        for(j=0;j<(1<<n);j++)
            din[j|v[i].masca]=min(din[j|v[i].masca],din[j]+v[i].cost);
        if((din[(1<<n)-1]+monitoare)<rasp)
            rasp=(din[(1<<n)-1]+monitoare);
    }

    if(rasp==inf)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<rasp<<'\n';

    return 0;
}