#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e6+5;

int n, m;

int32_t main()
{
    IOS;
	cin>>n>>m;
    if(n<m)
        swap(n, m);
    int ans1=0;
    for(int i=1;i<=m;i++)
    {
        ans1+=n/2;
        if(i%2)
            ans1+=n%2;
    }
    int ans2=0;
    for(int i=1;i<=n;i++)
    {
        ans2+=m/2;
        if(i%2)
            ans2+=m%2;
    }
    if(m==1)
        ans1=max(ans1, n);
    else if(m==2)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i%4<=1)
                ans+=2;
        }
        cout<<ans;
        return 0;
    }
    cout<<max(ans1, ans2);
    return 0;
}