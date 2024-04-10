#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (53)
#define MOD ((ll)1e9+7)

int n,d[N],dp[2][2*N][2*N][N][N];

void add(int &x,int y){x=(x+y)%MOD;}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i];
	dp[1][d[1]][0][1][0]=1;
	for(int i=1;i<n;i++)
	{
		bool p=(i&1);
		for(int cnt1=0;cnt1<=2*i+1;cnt1++)
			for(int cnt2=0;cnt2<=2*i+1-cnt1;cnt2++)
				for(int v1=0;v1<=i;v1++)
					for(int v2=0;v2<=i-v1;v2++)
					{
						ll now=(dp[p][cnt1][cnt2][v1][v2]%MOD);
						if(!now)continue;
						if(cnt2)add(dp[!p][cnt1+(d[i+1]-1)][cnt2-1][v1+1][v2],max(0ll,(now*(cnt2-v2))%MOD));
										add(dp[!p][cnt1+(d[i+1]-1)][cnt2-1][v1+1][v2-1],max(0ll,(now*(2*v2-cnt2))%MOD));
						if(cnt1 && cnt2)add(dp[!p][cnt1+(d[i+1]-2)-1][cnt2-1][v1+1-(d[i+1]==2)][v2],max(0ll,(now*(cnt2-v2)*(cnt1-v1))%MOD)),
										add(dp[!p][cnt1+(d[i+1]-2)-1][cnt2-1][v1+1-(d[i+1]==2)][v2-1],max(0ll,(now*(2*v2-cnt2)*(cnt1-v1))%MOD)),
										add(dp[!p][cnt1+(d[i+1]-2)-1][cnt2-1][v1-(d[i+1]==2)][v2],max(0ll,(now*(cnt2-v2)*(2*v1-cnt1))%MOD)),
										add(dp[!p][cnt1+(d[i+1]-2)-1][cnt2-1][v1-(d[i+1]==2)][v2-1],max(0ll,(now*(2*v2-cnt2)*(2*v1-cnt1))%MOD));
						if(d[i+1]==3 && cnt1>=2 && cnt2)add(dp[!p][cnt1+(d[i+1]-3)-2][cnt2-1][v1][v2],max(0ll,(now*(cnt2-v2)*(cnt1-v1)*(cnt1-v1-1)/2)%MOD)),
										add(dp[!p][cnt1+(d[i+1]-3)-2][cnt2-1][v1][v2-1],max(0ll,(now*(2*v2-cnt2)*(cnt1-v1)*(cnt1-v1-1)/2)%MOD)),
										add(dp[!p][cnt1+(d[i+1]-3)-2][cnt2-1][v1-1][v2],max(0ll,(now*(cnt2-v2)*(2*v1-cnt1)*(cnt1-v1))%MOD)),
										add(dp[!p][cnt1+(d[i+1]-3)-2][cnt2-1][v1-1][v2-1],max(0ll,(now*(2*v2-cnt2)*(2*v1-cnt1)*(cnt1-v1))%MOD));
						if(d[i+1]==3 && v1>=2 && cnt2)add(dp[!p][cnt1+(d[i+1]-3)-2][cnt2-1][v1-2][v2],max(0ll,(now*(cnt2-v2)*(2*v1-cnt1)*(2*v1-cnt1-1)/2)%MOD)),
										add(dp[!p][cnt1+(d[i+1]-3)-2][cnt2-1][v1-2][v2-1],max(0ll,(now*(2*v2-cnt2)*(2*v1-cnt1)*(2*v1-cnt1-1)/2)%MOD));
						if(!cnt2 && cnt1)add(dp[!p][d[i+1]-1][cnt1-1][1][v1],max(0ll,(now*(i>1?(cnt1-v1):1))%MOD)),
										add(dp[!p][d[i+1]-1][cnt1-1][1][v1-1],max(0ll,(now*(i>1?(2*v1-cnt1):0))%MOD));
			            dp[p][cnt1][cnt2][v1][v2]=0;
					}
	}
	cout<<(dp[(n&1)][0][0][0][0]%MOD);
	return 0;
}