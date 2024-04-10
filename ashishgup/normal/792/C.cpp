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
const int M=505;
const int LG=19;

int n, rem=0;
int index[N], cache[N][5][2];
pair<int, int> path[N][5][2];
string s;

int dp(int i, int rem, int taken)
{
    if(i>=n)
    {
        if(!taken)
            return -1e6;
        if(rem!=0)
            return -1e6;
        return 0;
    }
    if(cache[i][rem][taken]!=-1)
        return cache[i][rem][taken];
    int cur=(s[i]-'0')%3;
    int newrem=(cur+rem)%3;
    int ans=dp(i+1, rem, taken);
    path[i][rem][taken]=mp(rem, taken);
    if(!taken)
    {
        if(s[i]!='0')
        {
            if(1+dp(i+1, newrem, 1)>ans)
            {
                ans=1+dp(i+1, newrem, 1);
                path[i][rem][taken]=mp(newrem, 1);
            }
        }
    }
    else
    {
        if(1+dp(i+1, newrem, 1)>ans)
        {
            ans=1+dp(i+1, newrem, 1);
            path[i][rem][taken]=mp(newrem, 1);
        }
    }
    cache[i][rem][taken]=ans;
    return cache[i][rem][taken];
}

int32_t main()
{
    IOS;
    memset(cache, -1, sizeof(cache));
    cin>>s;
    n=s.size();
    int len=dp(0, 0, 0);  
    trace1(len);  
    if(len<0)
    {
        if(s.find('0')!=string::npos)
        {
            cout<<"0";
        }
        else
        {
            cout<<"-1";
        }
        return 0;
    }
    else
    {
        int i=0, rem=0, taken=0;
        int start=-1;
        int prevval=1e6;
        while(i<n)
        {
        	pair<int, int> next=path[i][rem][taken];
            if(next.ss==1)
            {
                start=i;
            }
            if(start!=-1)
            {
                index[cache[i][rem][taken]]=i;
            }
            rem=next.ff;
            taken=next.ss;
            i++;
        }
        for(int i=len;i>=1;i--)
        {
            cout<<s[index[i]];
        }
    }    
    return 0;
}