#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)
#define MOD ((ll)1e9+7)

ll n,a[26],dp_cnt[N],dp_min[N],maxi;
bool mark[26];
string s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	for(int i=0;i<26;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		dp_min[i]=(ll)1e6;
		memset(mark,0,sizeof mark);
		for(int j=i;j>=0;j--)
		{	
			mark[(s[j]-'a')]++;
			bool flg=0;
			for(int p=0;p<26;p++)if(mark[p] && i-j+1>a[p]){flg=1;break;}
			if(flg)break;
			dp_cnt[i]+=(j?dp_cnt[j-1]:1);dp_cnt[i]%=MOD;
			maxi=max(maxi,(ll)i-j+1);
			dp_min[i]=min(dp_min[i],(j?dp_min[j-1]:0)+1);
		}
	}
	cout<<dp_cnt[n-1]<<"\n"<<maxi<<"\n"<<dp_min[n-1];
	return 0;
}