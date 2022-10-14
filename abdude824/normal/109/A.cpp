#include <bits/stdc++.h>
#define MOD 1000000007
#define Nmax 1000005
#define pb push_back
#define mp make_pair
#define INF 2000000000
#define eps 0.000000000001

using namespace std;

int n;
int a,b;

inline int Pow_Log(int x, int p)
{
    int sol=1;
    while(p)
    {
        if(p&1)
        {
            sol=(1LL*sol*x)%MOD; --p;
        }
        p>>=1; x=(1LL*x*x)%MOD;
    }
    return sol;
}

int main()
{
    int i,j,minn=INF;
    #ifndef ONLINE_JUDGE
        freopen ("date.in","r",stdin);
        freopen ("date.out","w",stdout);
    #endif
    cin.sync_with_stdio(0);
    cin>>n;
    for(i=0;i<=1000000;++i)
    {
        if(4*i>n || (n-4*i)%7) continue;
        j=(n-4*i)/7;
        if(minn>i+j)
        {
            minn=i+j; a=i; b=j;
        }
        else
            if(minn==i+j && i>a)
            {
                a=i; b=j;
            }
    }
    if(minn==INF)
    {
        cout<<"-1"; return 0;
    }
    for(i=1;i<=a;++i) cout<<4;
    for(i=1;i<=b;++i) cout<<7;
    return 0;
}