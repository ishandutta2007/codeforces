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
const int MOD=1e9+7;

map<char, int> m;
map<char, int> f, l;

int32_t main()
{
    IOS;
    string s;
    cin>>s;
   	int n=s.size();
   	for(int i=0;i<n;i++)
   	{
   		m[s[i]]++;
   		if(f.find(s[i])==f.end())
   			f[s[i]]=i;
   		l[s[i]]=i;
   	}
   	if(m['a']<1 || m['b']<1 || m['c']<1)
   	{
   		cout<<"NO";
   		return 0;
   	}
   	if(f['b']<l['a'] || f['c']<l['b'])
   	{
   		cout<<"NO";
   		return 0;
   	}
   	if(m['c']!=m['b'] && m['c']!=m['a'])
   	{
   		cout<<"NO";
   		return 0;
   	}
   	cout<<"YES";
    return 0;
}