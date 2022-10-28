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

int n, x1, x2;
pair<int, int> a[N];

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
	return p1.second<p2.second;
}

int32_t main()
{
	IOS;
	cin>>n>>x1>>x2;
	int storex1=x1, storex2=x2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1, a+n+1);
	vector<int> v1, v2;
	for(int i=n-1;i>=1;i--)
	{
		int curmin=a[i].first;
		int sz1=(x1-1)/curmin + 1;
		if(i+sz1<=n)
		{
			int curmin2=a[i+sz1].first;
			int sz2=(x2-1)/curmin2 + 1;
			if(i+sz1+sz2<=n+1)
			{
				for(int j=i;j<i+sz1;j++)
				{
					v1.push_back(a[j].second);
				}
				for(int j=i+sz1;j<i+sz1+sz2;j++)
				{
					v2.push_back(a[j].second);
				}
				break;
			}
		}
		int curmin3=a[i].first;
		int sz3=(x2-1)/curmin3 + 1;
		if(i+sz3<=n)
		{
			int curmin4=a[i+sz3].first;
			int sz4=(x1-1)/curmin4 + 1;
			if(i+sz3+sz4<=n+1)
			{
				for(int j=i;j<i+sz3;j++)
				{
					v2.push_back(a[j].second);
				}
				for(int j=i+sz3;j<i+sz3+sz4;j++)
				{
					v1.push_back(a[j].second);
				}
				break;
			}
		}
	}
	if(v1.size()==0 || v2.size()==0)
	{
		cout<<"No";
		return 0;
	}
	sort(a+1, a+n+1, comp);
	cout<<"Yes"<<endl;
	cout<<v1.size()<<" "<<v2.size()<<endl;
	for(auto it:v1)
		cout<<it<<" ";
	cout<<endl;
	for(auto it:v2)
		cout<<it<<" ";
	cout<<endl;
	return 0;
}