#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=2e5+9;
int ans,n,m,pos_max[N],now;
char s[N],t[N];
int main()
{
	n=read(),m=read();
	//for(int i=0;i<=1000;i++)pos_max[i]=-1;
	cin>>s;
	cin>>t;
	now=n-1;
	for(int i=m-1;i>=0;i--)
	{
		while(s[now]!=t[i])now--;
		//if(s[now]!=t[i])break;
		pos_max[i]=now;
		now--;
		//cout<<pos_max[i]<<" "<<i<<endl;
	}
	now=-1;
	for(int i=0;i<m;i++)
	{
		if(i!=0)ans=max(ans,pos_max[i]-now);
		now++;
		while(s[now]!=t[i])now++;
		//if(s[now]!=t[i])break;	
	}
	cout<<ans<<endl;
	return 0;
}