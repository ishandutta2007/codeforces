#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
int n,k,mark[N];

bool query(int x)
{
    char ch;
    cout<<"? "<<x<<"\n";
    cout.flush();
    cin>>ch;
    return (ch=='Y');
}

void rese()
{
    cout<<"R\n";
    cout.flush();
}

int main()
{
    //freopen("ss.inp","r",stdin);
    cin>>n>>k;
    if (k==1)
    {
        int res=1;
        for (int i=2;i<=n;i++)
        {
            int check=1;
            for (int j=1;j<i;j++)
            {
                query(j);
                if (query(i)) check=0;
            }
            if (check) res++;
        }
        cout<<"! "<<res<<"\n";
        cout.flush();
        return 0;
    }
    k/=2;
    for (int i=1;i<=2*k;i++)
        if (query(i)) mark[i]=1;
    rese();
    for (int i=3;i<=n/k;i++)
    {
        for (int j=1;j<=(i-1)/2;j++)
        {
            for (int t=(j-1)*k*2+1;t<=(j-1)*k*2+k;t++)
                if (!mark[t]) query(t);
            for (int t=(i-1)*k+1;t<=i*k;t++)
                if (!mark[t] && query(t)) mark[t]=1;
            for (int t=(j-1)*k*2+k+1;t<=j*k*2;t++)
                if (!mark[t] && query(t)) mark[t]=1;
            rese();
        }
        if ((i-1)&1)
        {
            for (int t=(i-2)*k+1;t<=(i-1)*k;t++)
                if (!mark[t]) query(t);
            for (int t=(i-1)*k+1;t<=i*k;t++)
                if (!mark[t] && query(t)) mark[t]=1;
            rese();
        }
    }
    int res=0;
    for (int i=1;i<=n;i++)
        if (!mark[i]) res++;
    cout<<"! "<<res<<"\n";
    cout.flush();
    return 0;
}