#include <bits/stdc++.h>
using namespace std;
long long n,a,b,k1,k,c[1000000],m,type[1000000],ans,sum;
string st;
long long month[13]={29, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
double sqr(double u)
{
    return(u*u);
}
string string_int (long long u)
{
    string str;
    while (u!=0)
    {
        str+=u%10+48;
        u/=10;
    }
    reverse(str.begin(),str.end());
    return(str);
}
long long nsk (long long i, long long j)
{
    while (i!=0 && j!=0)
        if (i>j) i%=j; else j%=i;
    return(i+j);
}
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        scanf("%d", &c[i]);
    }
    for (int i=1;i<=k;i++)
    {
        scanf("%d", &a);
        type[a]=1;
    }
    for (int i=1;i<=n;i++)
    {
        if (type[i]==0)
        {
            m=i-1;
            if (m==0) m=n;
            if (type[m]!=1)
                ans+=c[i]*c[m];
        }
    }
    for (int i=1;i<=n;i++)
        if (type[i]==0) sum+=c[i];
    for (int i=1;i<=n;i++)
    {
        if (type[i]==1) ans+=sum*c[i],sum+=c[i];

    }


    cout<<ans;
}