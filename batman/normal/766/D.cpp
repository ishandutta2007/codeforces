#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)

ll n,m,q,par[N],op[N];
string s[N];

ll root(ll x){if(par[x]==-1)return x;return par[x]=root(par[x]);}
ll _find(string x){return lower_bound(s,s+n,x)-s;}

char inp[25];

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++)scanf(" %s",&inp),s[i]=inp,par[i]=-1,op[i]=-1;
	sort(s,s+n);
	for(int i=0;i<m;i++)
	{
		ll t,x,y;
		string in1,in2;
		scanf("%d %s",&t,&inp);in1=inp;
		scanf(" %s",&inp);in2=inp;
		x=_find(in1);y=_find(in2);
		if(t==1)
		{
			x=root(x);y=root(y);
			if(op[y]!=-1 && x==root(op[y])){cout<<"NO\n";continue;}
			if(x==y){cout<<"YES\n";continue;}
			if(op[x]==-1 && op[y]==-1){par[x]=y;cout<<"YES\n";continue;}
			if(op[x]==-1){par[x]=y;cout<<"YES\n";continue;}
			if(op[y]==-1){par[y]=x;cout<<"YES\n";continue;}
			ll p=root(op[x]),q=root(op[y]);
			par[p]=q;par[x]=y;
			cout<<"YES\n";
			continue;
		}
		if(t==2)
		{
			x=root(x);y=root(y);
			if(x==y){cout<<"NO\n";continue;}
			if(op[x]!=-1 && y==root(op[x])){cout<<"YES\n";continue;}
			if(op[x]==-1 && op[y]==-1){op[x]=y;op[y]=x;cout<<"YES\n";continue;}
			if(op[x]==-1){par[root(op[y])]=x;op[x]=y;cout<<"YES\n";continue;}
			if(op[y]==-1){par[root(op[x])]=y;op[y]=x;cout<<"YES\n";continue;}
			ll p=root(op[x]),q=root(op[y]);
			par[p]=y;par[q]=x;
			op[x]=y;op[y]=x;
			cout<<"YES\n";
			continue;
		}
	}
	for(int i=0;i<q;i++)
	{
		string in1,in2;
		ll x,y;
		scanf(" %s",&inp);in1=inp;
		scanf(" %s",&inp);in2=inp;
		x=_find(in1);y=_find(in2);
		x=root(x);y=root(y);
		if(x==y)cout<<"1\n";
		else if(op[y]!=-1 && x==root(op[y]))cout<<"2\n";
		else cout<<"3\n";
	}
	return 0;
}