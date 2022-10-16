#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=0x3f3f3f3f;
int n,m,s[1000002],dis[102][102],now,ans=1,pos,pd[1000002];
char p[102][102];
int main()
{
	memset(dis,0x3f,sizeof(dis)); 
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
			if(p[i][j]-'0')dis[i][j]=1;
		}
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>s[i];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	pos=s[1],now=dis[s[1]][s[2]];
	for(int i=2;i<m;i++){
		if(pos!=s[i+1]&&now+dis[s[i]][s[i+1]]<=dis[pos][s[i+1]])
			pd[i]=1,now+=dis[s[i]][s[i+1]];
		else now=dis[s[i]][s[i+1]],pos=s[i],ans++;
	}
	cout<<ans+1<<endl;
	cout<<s[1]<<" ";
	for(int i=2;i<m;i++)
		if(!pd[i])
			cout<<s[i]<<" ";
	cout<<s[m]<<endl;
	return 0;
}
/*
4
0110
0010
0001
1000
4
1 2 3 4
*/