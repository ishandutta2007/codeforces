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

const int N=100;

int n, L;
int a[N], b[N];

int32_t main()
{
    IOS;
    cin>>n>>L;
    int storeL=L;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
    	b[i]=min(2*b[i-1], a[i]);
    }
    for(int i=n+1;i<=31;i++)
    {
    	b[i]=2*b[i-1];
    }
    vector<int> pos;
    int ans=0, cur=0;
    int ctr=1;
    while(L>0)
    {
    	if(L%2)
    	{
    		ans+=b[ctr];
    	}
    	L/=2;
    	ctr++;
    }
    pos.push_back(ans);
    int tempans=0;
    for(int i=30;i>=0;i--)
    {
    	if(storeL&(1LL<<i))
    	{
    		tempans+=b[i+1];
    	}
    	else
    	{
    		pos.push_back(b[i+1] + tempans);
    	}
    }
    pos.push_back(tempans);
    sort(pos.begin(), pos.end());
    cout<<*(pos.begin());
    return 0;
}