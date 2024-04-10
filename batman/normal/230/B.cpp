#include <iostream>
#include <cmath>
using namespace std;
#define N (1000*1000)
#define ll long long


bool mark[N+100];

void erat()
{
    mark[0]=mark[1]=true;
    for(ll i=2;i<=N;i++)
        if(mark[i]==false)
            for(ll j=i*2;j<=N;j+=i)
                mark[j]=true;
}

int main()
{
    ll n,a,p1;
    double p2;
    erat();
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        p1=(int)sqrt((double)a);
        p2=(double)sqrt(double(a));
        if(p1==p2 && mark[p1]==false)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}