#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (30)
#define INF ((ll)1e9)

ll n,m,ans;
bool dp[30][30][30][30];
string s[N];

int main()
{
	ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>s[i];
    for(int satr1=0;satr1<n;satr1++)
    	for(int satr2=satr1;satr2<n;satr2++)
    		for(int soton1=0;soton1<m;soton1++)
    			for(int soton2=soton1;soton2<m;soton2++)
    			{
    				dp[satr1][satr2][soton1][soton2]=1;
    				if(soton2!=soton1 && !dp[satr1][satr2][soton1][soton2-1])
    					dp[satr1][satr2][soton1][soton2]=0;
    				for(int i=satr1;i<=satr2;i++)
						if(s[i][soton2]=='1')
							dp[satr1][satr2][soton1][soton2]=0;
    				if(dp[satr1][satr2][soton1][soton2])
						ans=max(ans,(ll)(satr2-satr1+1)*2+(soton2-soton1+1)*2);	
				}
	cout<<ans;			
    return 0;
}