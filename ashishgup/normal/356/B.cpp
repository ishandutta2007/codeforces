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

const int N=1e6+5;

int n, m, x1 ,y1;
string x, y;
map<char, int> a[N], b[N];

int32_t main()
{
    IOS;
	cin>>n>>m;
    cin>>x>>y;
    x1=x.size();
    y1=y.size();
    int mult=n*gcd(x1,y1)/y1;
    int gcd1=gcd(x1, y1);
    for(int i=0;i<x1;i++)
    {
        a[i%gcd1][x[i]]++;
    }
    for(int i=0;i<y1;i++)
    {
        b[i%gcd1][y[i]]++;
    }
    int ans=0;
    for(int i=0;i<gcd1;i++)
    {
        int totala=0;
        for(auto it:a[i])
        {
            totala+=it.ss;
        }
        int totalb=0;
        for(auto it:b[i])
        {
            totalb+=it.ss;
        }   
        ans+=totala*totalb;
        for(char ch='a';ch<='z';ch++)
        {
            if(a[i].find(ch)==a[i].end())
                continue;
            if(b[i].find(ch)==b[i].end())
                continue;
            ans-=(a[i][ch]*b[i][ch]);
        }
    }
    cout<<ans*mult;
    return 0;
}