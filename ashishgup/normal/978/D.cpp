#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int a[N], b[N];
int dx[3]={-1, 0, +1};
int dy[3]={-1, 0, +1};

int32_t main()
{
	IOS;
	cin>>n;
	if(n<=2)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=INT_MAX;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			int x=a[1]+dx[i];
			int y=a[2]+dy[j];
			int diff=y-x;
			int check=1, reqd=0;
			b[1]=x;
			b[2]=y;
			for(int i=3;i<=n;i++)
			{
				if(abs(a[i]-b[i-1]-diff)>1)
					check=0;
				reqd+=abs(a[i]-b[i-1]-diff);
				b[i]=b[i-1]+diff;
			}	
			reqd+=(i!=1);
			reqd+=(j!=1);
			if(check)
				ans=min(ans, reqd);
		}
	}
	if(ans==INT_MAX)
		cout<<"-1";
	else
		cout<<ans;
	return 0;
}