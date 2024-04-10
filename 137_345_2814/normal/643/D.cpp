#include<cstdio>
#include<set>
#include<queue>
using namespace std;
#define N 1000500
int n,m,a,b,c,f[N],in[N];
long long v[N],su[N],fg[N];
multiset<long long> s[N],v1[N];
priority_queue<long long> tp1,tp2,tp3,tp4;
void del(int i){if(in[i]>2)tp2.push(-*s[i].begin()-fg[i]),tp4.push(*s[i].rbegin()+fg[i]);}
void ins(int i){if(in[i]>2)tp1.push(-*s[i].begin()-fg[i]),tp3.push(*s[i].rbegin()+fg[i]);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&v[i]),in[i]=2;
	for(int i=1;i<=n;i++)scanf("%d",&f[i]),in[f[i]]++,v1[f[i]].insert(i);
	for(int i=1;i<=n;i++)
	{
		long long tp=v[i],s1=tp/in[i];
		for(multiset<long long>::iterator it=v1[i].begin();it!=v1[i].end();it++)
		su[*it]+=s1,tp-=s1;
		su[f[i]]+=s1,tp-=s1;
		su[i]+=tp;
	}
	for(int i=1;i<=n;i++)s[f[i]].insert(su[i]);
	for(int i=1;i<=n;i++)if(v1[i].size())ins(i);
	while(m--)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d%d",&b,&c);
			int l1=f[b],l2=f[l1],l3=f[l2];
			del(l1);
			s[l1].erase(s[l1].find(su[b]));
			su[b]+=fg[l1];su[b]-=v[l1]/in[l1];
			long long vl1=v[l1]/(in[l1]-1)-v[l1]/in[l1],vl2=v[l1]-v[l1]/(in[l1]-1)*(in[l1]-2)-v[l1]+v[l1]/in[l1]*(in[l1]-1);
			in[l1]--;fg[l1]+=vl1;
			del(l2);s[l2].erase(s[l2].find(su[l1]));
			su[l1]+=vl2-v[b]/in[b];s[l2].insert(su[l1]);ins(l2);
			del(l3);s[l3].erase(s[l3].find(su[l2]));
			su[l2]+=vl1;s[l3].insert(su[l2]);ins(l3);
			ins(l1);f[b]=c;
			l1=f[b],l2=f[l1],l3=f[l2];
			del(l1);
			su[b]-=fg[l1];su[b]+=v[l1]/in[l1];
			s[l1].insert(su[b]);
			vl1=-v[l1]/in[l1]+v[l1]/(in[l1]+1),vl2=-v[l1]+v[l1]/in[l1]*(in[l1]-1)+v[l1]-v[l1]/(in[l1]+1)*in[l1];
			in[l1]++;fg[l1]+=vl1;
			del(l2);s[l2].erase(s[l2].find(su[l1]));
			su[l1]+=vl2+v[b]/in[b];s[l2].insert(su[l1]);ins(l2);
			del(l3);s[l3].erase(s[l3].find(su[l2]));
			su[l2]+=vl1;s[l3].insert(su[l2]);ins(l3);
			ins(l1);
		}
		else if(a==2)scanf("%d",&b),printf("%lld\n",su[b]+fg[f[b]]);
		else
		{
			while(tp1.size()&&tp2.size()&&tp1.top()==tp2.top())tp1.pop(),tp2.pop();
			while(tp3.size()&&tp4.size()&&tp3.top()==tp4.top())tp3.pop(),tp4.pop();
			printf("%lld %lld\n",-tp1.top(),tp3.top());
		}
	}
}