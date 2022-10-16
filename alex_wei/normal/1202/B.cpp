#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
string s;
const ll inf=1e9;
ll p[10][10],num[10][10][10][10],ans[10][10];
int main()
{
	cin>>s;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++) 
				for(int l=0;l<10;l++){
					num[i][j][k][l]=inf;
					for(int m=0;m<=10;m++)
						for(int n=0;n<=10;n++)
							if((i+m*k+n*l)%10==j&&m+n>0)
								num[i][j][k][l]=min(num[i][j][k][l],(ll)m+n-1);
				}
	for(int i=1;i<s.size();i++)
		p[s[i-1]-'0'][s[i]-'0']++;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++)
				for(int l=0;l<10;l++)
					ans[k][l]+=num[i][j][k][l]*p[i][j];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			if(ans[i][j]>=inf)cout<<"-1 ";
			else cout<<ans[i][j]<<" ";
			if(j==9)cout<<endl;
		}
	return 0;
}