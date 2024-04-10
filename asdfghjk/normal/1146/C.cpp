#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
struct node
{
	int l,r;
}p[105],q[105];
int t,n,w,ans,len,cnt,i,j,k,k1,k2,a1[105],a2[105];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		p[len=1]=(node){1,n};
		while(len>0)
		{
			k1=k2=0;
			cnt=0;
			for(i=1;i<=len;++i)
			{
				j=(p[i].l+p[i].r)/2;
				for(k=p[i].l;k<=j;++k)
					a1[++k1]=k;
				for(k=j+1;k<=p[i].r;++k)
					a2[++k2]=k;
				if(p[i].l!=j)
					q[++cnt]=(node){p[i].l,j};
				if(j+1!=p[i].r)
					q[++cnt]=(node){j+1,p[i].r};
			}
			cout<<k1<<' '<<k2;
			for(k=1;k<=k1;++k)
				cout<<' '<<a1[k];
			for(k=1;k<=k2;++k)
				cout<<' '<<a2[k];
			cout<<endl;
			cout.flush();
			cin>>k;
			ans=max(ans,k);
			len=cnt;
			for(i=1;i<=len;++i)
				p[i]=q[i];
		}
		cout<<-1<<' '<<ans<<endl;
	}
	return 0;
}