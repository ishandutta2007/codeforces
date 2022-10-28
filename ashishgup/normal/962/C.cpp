#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
 
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
const int N=1e6+5;

set<int> sq;
string str;
map<int, int> cache;

int recurse(string s)
{
    if(s.size()==1)
    {
        int num=stoll(s);
        if(sq.find(num)!=sq.end())
            return 0;
        return 1e9;
    }
    int num=stoll(s);
    if(cache.find(num)!=cache.end())
    {
        return cache[num];
    }
    if(sq.find(num)!=sq.end())
    {
        cache[num]=0;
        return 0;
    }
    int sz=s.size();
    int ans=1e9;
    for(int i=0;i<sz;i++)
    {
        string cur="";
        for(int j=0;j<sz;j++)
        {
            if(j==i)
                continue;
            cur+=s[j];
        }
        if(cur[0]!='0')
        {
            ans=min(ans, 1+recurse(cur));
        }
    }
    cache[num]=ans;
    return ans;
}

int32_t main()
{
    IOS;
    for(int i=1;i<=1e5;i++)
    {
        sq.insert(i*i);
    }
    cin>>str;
    int ans=recurse(str);
    if(ans>=100)
    {
        cout<<"-1";
        return 0;
    }
    cout<<ans;
    return 0;
}