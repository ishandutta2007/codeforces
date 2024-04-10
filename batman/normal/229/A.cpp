#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (110)
#define INF ((ll)1e11)
#define MOD ((ll)1e9+7)

ll n,m,ans=INF,d[2][11*1000];
string s[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		ll l=-1,p=INF,q=INF;
		for(int j=0;j<m;j++)
			if(s[i][j]=='1')
			{
				p=j+1;
				break;
			}
		for(int j=m-1;j>=0;j--)
			if(s[i][j]=='1')
			{
				q=m-j;
				break;	
			}
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='1')l=j;
			d[1][j]=((l==-1)?INF:j-l);
		}
		l=-1;
		for(int j=m-1;j>=0;j--)
		{
			if(s[i][j]=='1')l=j;
			d[0][j]+=min(d[1][j],min(((l==-1)?INF:l-j),min(p+(m-1)-j,q+j)));
		}
		
	}
	for(int i=0;i<m;i++)ans=min(ans,d[0][i]);
	cout<<((ans>=(ll)1e9)?-1:ans);
    return 0;
}