#include<bits/stdc++.h>
using namespace std;
char s1[100005],s2[100005];
int t1[100005],t2[100005];
int q[200005];
void rev(int l,int r)
{
	int mid=l+r>>1;
	for(int i=l;i<=mid;i++)swap(t1[i],t1[r-i+l]);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		scanf("%s%s",s1+1,s2+1);
		int ans=0,s=1,e=n,r=0;
		for(int i=1;i<=n;i++)t1[i]=s1[i]-'0',t2[i]=s2[i]-'0';
		for(int i=n;i>=1;i--)
		{
			int wz=s;
			if(r)wz=e;
			int ff=t1[wz];
			ff+=n-i;
			ff&=1;
			if(t2[i]==ff)q[++ans]=1,t1[wz]=!t2[i];
			q[++ans]=i;
//			rev(1,i);
			if(!r)s++,r=1;
			else e--,r=0;
		}
		printf("%d",ans);
		for(int i=1;i<=ans;i++)printf(" %d",q[i]);
		puts("");
	}
	return 0;
}