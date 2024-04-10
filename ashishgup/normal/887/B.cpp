#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e5+5;

int n;
int a[5][100];
int freq[N];

int process(int p, int q)
{
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=6;j++)
        {
            int cur=a[p][i]*10+a[q][j];
            freq[cur]++;
        }
    }
}

int process2(int p, int q, int r)
{
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=6;j++)
        {
            for(int k=1;k<=6;k++)
            {
                int cur=a[p][i]*100+a[q][j]*10+a[r][k];
                freq[cur]++;
            }
        }
    }
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            cin>>a[i][j];
            freq[a[i][j]]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            process(i, j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            for(int k=1;k<=n;k++)
            {
                if(k==i || k==j)
                    continue;
                process2(i, j, k);
            }
        }
    }
    for(int i=1;;i++)
    {
        if(freq[i]==0)
        {
            cout<<i-1;
            return 0;
        }
    }
    return 0;
}