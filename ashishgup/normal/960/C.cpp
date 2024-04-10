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

int x, d;

int32_t main()
{
    IOS;
    cin>>x>>d;
    int elem=1;
   	vector<int> v;
   	for(int i=32;i>=1;i--)
   	{
   		int cur=1LL<<i;
   		cur-=1;
   		if(x>=cur)
   		{
   			for(int j=1;j<=i;j++)
   			{
   				v.push_back(elem);
   			}
   			elem+=(d+1);
   			x-=cur;
   			i++;
   		}
   	}
   	cout<<v.size()<<endl;
   	for(auto it:v)
   	{
   		cout<<it<<" ";
   	}
    return 0;
}