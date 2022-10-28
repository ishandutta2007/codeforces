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

const int N=105;

int n, m, len, ans=0, starti, startj;
map<int, int> store;
char a[N][N];
string s;
char b[4]={'u', 'd', 'l', 'r'};
int xd[4]={-1, 1, 0, 0};
int yd[4]={0, 0, -1, 1};

int check(int i, int j, int k)
{
	if(i<=0||i>n||j<=0||j>m)
		return 0;
	if(a[i][j]=='#')
		return 0;
	if(a[i][j]=='E')
		return 1;
	if(k==len)
		return 0;
	int cur=s[k]-'0';
	int ind=store[cur];
	return check(i+xd[ind], j+yd[ind], k+1);
}	

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		cin>>a[i][j];
    		if(a[i][j]=='S')
    		{
    			starti=i;
    			startj=j;
    		}
    	}
    }
    cin>>s;
    len=s.size();
    vector<int> v;
    for(int i=0;i<=3;i++)
    {
    	v.push_back(i);
    }
    do
    {
    	store.clear();
    	for(int i=0;i<=3;i++)
    	{
    		store[v[i]]=i;
    	}
    	ans+=check(starti, startj, 0);

    }
    while(next_permutation(v.begin(), v.end()));
    cout<<ans;
    return 0;
}