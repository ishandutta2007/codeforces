#include<bits/stdc++.h>
using namespace std;
long long a,b,an,v[100005],d[100005],cn,k,c,u[100005],vv[100005],uu[100005],t[100004];
char s[100005];
struct p
{
	long long q,w,e;
	bool operator < (const p &aa) const
	{
		if(q==aa.q) return w>aa.w;
		return q<aa.q;
	}
};
priority_queue<p> qu;
int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
	for(int i=1;i<=k;i++) scanf("%lld",&d[i]),v[d[i]]++,u[d[i]]=i;
	for(int i=1;i<=a;i++) vv[i]=v[i],uu[i]=u[i];
	if(a==b)
	{
		if(c==k)
		{
			for(int i=1;i<=a;i++)
			{
				if(v[i]) printf("1 ");
				else printf("3 ");
			}
		}
		else
		{
			for(int i=1;i<=a;i++)
			{
				if(v[i]) printf("1 ");
				else printf("2 ");
			}
		}
		return 0;
	}
	if(c==k)
	{
		for(int i=1;i<=a;i++) qu.push(p{v[i],u[i],i});
		for(int i=1;i<=b;i++)
		{
			p r=qu.top();qu.pop();
			if(v[r.e]!=0) t[r.e]=1;
		}
		for(int i=1;i<=a;i++)
		{
			if(t[i]) printf("1 ");
			else printf("3 ");
		}
		return 0;
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++) qu.push(p{v[j],u[j],j});
		long long tt=b,cnn=k,fl=1;
//		qu.pop();
//		cout<<tt<<" "<<qu.size()<<" "<<qu.top().e<<"\n";
		while(!qu.empty())
		{
			if(tt==0)
			{
				fl=0;break;
			}
			p r=qu.top();qu.pop();
			if(r.q==0)
			{
				fl=0;break;
			}
//			cout<<r.e<<" "<<r.q<<" "<<r.w<<"\n";
			if(r.e!=i){tt--;continue;}
			p rr=r;
			r=qu.top();qu.pop();
			cnn++;
			if(cnn>c)
			{
				break;
			}
			r.q++;r.w=cnn;qu.push(r);qu.push(rr);
		}//cout<<"\n";
		while(!qu.empty()) qu.pop();
		if(fl)
		{
			printf("1 ");continue;
		}
		cnn=k;fl=0;
		for(int j=k+1;j<=c;j++) cnn++,v[i]++,u[i]=cnn;
		for(int j=1;j<=a;j++) qu.push(p{v[j],u[j],j});
//		cout<<v[i]<<" "<<u[i]<<"\n";
//		cout<<qu.top().e<<" ";
		for(int j=1;j<=b;j++)
		{
			p r=qu.top();qu.pop();
			if(v[r.e]==0) break;
			if(r.e==i)
			{
				fl=1;break;
			}
		}
		while(!qu.empty()) qu.pop();
		if(fl) printf("2 ");
		else printf("3 ");
		v[i]=vv[i],u[i]=uu[i];
	}
	return 0;
}
//2 2 1 1
//1
//3 2 1 1
//3
//23 9 2 1
//1