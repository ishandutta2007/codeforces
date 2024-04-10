#include<cstdio>
#include<queue>
#define N 205000
//#define double long double
using namespace std;
struct sth{double s;int v,x,y;};
bool operator <(sth a,sth b){return a.s==b.s?(a.v<b.v):a.s<b.s;}
priority_queue<sth> tp1,tp2,tp3,tp4;
int n,m,q,a,b,v[N],r[N],s[N],su;
double as;
void pre()
{
	while(!tp2.empty()&&!tp1.empty()&&tp2.top().v==tp1.top().v&&tp1.top().s==tp2.top().s)tp1.pop(),tp2.pop();
	while(!tp4.empty()&&!tp3.empty()&&tp4.top().v==tp3.top().v&&tp3.top().s==tp4.top().s)tp3.pop(),tp4.pop();
}
void del(int b)
{
	as-=1.0*v[b]*s[b]/(s[b]+r[b]);
	if(s[b])tp4.push((sth){-1.0*v[b]*r[b]/(r[b]+s[b]-1)/(s[b]+r[b]),b,s[b],r[b]});
	if(s[b]<r[b])tp2.push((sth){1.0*v[b]*r[b]/(r[b]+s[b]+1)/(s[b]+r[b]),b,s[b]+1,r[b]});
	pre();
}
void ins(int b)
{
	as+=1.0*v[b]*s[b]/(s[b]+r[b]);
	if(s[b])tp3.push((sth){-1.0*v[b]*r[b]/(r[b]+s[b]-1)/(s[b]+r[b]),b,s[b],r[b]});
	if(s[b]<r[b])tp1.push((sth){1.0*v[b]*r[b]/(r[b]+s[b]+1)/(s[b]+r[b]),b,s[b]+1,r[b]});
	pre();
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)scanf("%d",&r[i]);
	for(int i=1;i<=n;i++)tp1.push((sth){1.0*v[i]/(r[i]+1),i,1,r[i]});
	for(int i=1;i<=m&&!tp1.empty();i++)
	{
		su++;
		sth vl=tp1.top();tp1.pop();
		s[vl.v]++;
		if(s[vl.v]<r[vl.v])
		tp1.push((sth){1.0*v[vl.v]*r[vl.v]/(r[vl.v]+s[vl.v]+1)/(s[vl.v]+r[vl.v]),vl.v,s[vl.v]+1,r[vl.v]});
	}
	for(int i=1;i<=n;i++)as+=1.0*v[i]*s[i]/(s[i]+r[i]);
	for(int i=1;i<=n;i++)if(s[i])
	tp3.push((sth){-1.0*v[i]*r[i]/(r[i]+s[i]-1)/(s[i]+r[i]),i,s[i],r[i]});
	while(q--)
	{
		if(a)printf("%.15lf\n",as);
		scanf("%d%d",&a,&b);
		if(a==1)
		{
			if(su<m)del(b),s[b]++,r[b]++,su++,ins(b);
			else if(!s[b]){del(b);r[b]++;ins(b);continue;}
			else
			{
				int st=b;
				del(b),r[b]++,s[b]--,su--,ins(b);
				if(!tp1.size())continue;
				b=tp1.top().v;
				del(b),s[b]++,su++,ins(b);
				if(s[st]==r[st]-1)
				{
					b=tp3.top().v;
					del(b),s[b]--,su--,ins(b);
					b=tp1.top().v;
					del(b),s[b]++,su++,ins(b);
				}
			}
		}
		else
		{
			if(s[b]==r[b])
			{
				del(b),s[b]--,r[b]--,su--,ins(b);
				if(!tp1.size())continue;
				b=tp1.top().v;
				del(b),s[b]++,su++,ins(b);
			}
			else
			{
				int st=b;
				b=tp3.top().v;
				del(b);if(b!=st)del(st);
				s[b]--;su--;r[st]--;
				ins(b);if(b!=st)ins(st);
				b=tp1.top().v;
				del(b),s[b]++,su++,ins(b);
			}
		}
	}
	printf("%.15lf\n",as);
}