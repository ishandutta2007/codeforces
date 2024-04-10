#include<cstdio>
using namespace std;
#define N 200500
int v1[N],v2[N],v3[N],s,t,head[N],cnt,is[N],fr[N],ct,st[N],fg,s1,s2,s3,s4,s5,a,b,st2[N],ct2,vl[N],c1,ins[N],n,fr2[N],is2[N],d1,is3[N];
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
void dfs(int u,int fa)
{
	if(!fg)st[++ct]=u;
	if(u==t)fg=1;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)dfs(ed[i].t,u);
	if(!fg)ct--;
}
bool check(int l,int r)
{
	t=r;ct=0;fg=0;dfs(l,0);
	for(int i=1;i<=n;i++)ins[i]=0;
	for(int i=1;i<=ct;i++)ins[st[i]]=1;
	for(int i=1;i<=n;i++)if(is[i]&&!ins[i])return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&v1[i]);if(!v1[i])s=i;}
	for(int i=1;i<=n;i++){scanf("%d",&v2[i]);if(!v2[i])t=i;}
	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b);
	dfs(s,0);s3=s,s4=t;
	for(int i=1;i<=n;i++)v3[i]=v1[i];
	for(int i=1;i<ct;i++)v3[st[i]]=v3[st[i+1]];
	v3[st[ct]]=0;
	int fg1=0;
	for(int i=1;i<=n;i++)
	if(v2[i]!=v3[i])
	{
		fg1=1;
		is[i]=1;
		for(int j=head[i];j;j=ed[j].next)fr[ed[j].t]++;
	}
	if(!fg1){printf("0 %d\n",ct-1);return 0;}
	for(int i=1;i<=n;i++)if(is[i]&&fr[i]<=1)vl[++c1]=i;
	if(c1>4){printf("-1\n");return 0;}
	for(int i=1;i<=c1&&fg1==1;i++)
	for(int j=i+1;j<=c1;j++)
	if(check(vl[i],vl[j])){s1=vl[i],s2=vl[j];fg1=2;break;}
	t=s2;ct=fg=0;dfs(s1,0);for(int i=1;i<=ct;i++)is3[st[i]]=1;
	if(fg1==1){printf("-1\n");return 0;}
	int v4=0;for(int i=1;i<=ct;i++)if(!is[st[i]]){if(v4){printf("-1\n");return 0;}v4=st[i];}
	if(!v4)
	{
		t=s1;ct=fg=0;dfs(s,0);
		if(ct>1&&!is[st[ct-1]])v4=st[ct-1],s1=v4;
		else
		{
			t=s2;ct=fg=0;dfs(s,0);
			if(ct>1&&!is[st[ct-1]])v4=st[ct-1],s2=v4;
			else
			{
				int st=1;
				for(int i=head[s];i;i=ed[i].next)
				if(!is[ed[i].t]){v4=ed[i].t,st=2;if(s1==s)s1=v4;else s2=v4;}
				if(st==1)
				{
					int st2=0,st3=(s1==s?s2:s1);
					for(int i=head[st3];i;i=ed[i].next)
					if(!is[ed[i].t]){v4=ed[i].t,st2=1;if(s1==s)s2=v4;else s1=v4;}
					if(!st2){printf("-1\n");return 0;}
				}
			}
		}	
	}
	else
	{
		t=v4;ct=0;fg=0;dfs(s,0);
		for(int i=1;i<=ct;i++)if(is3[st[i]]){v4=st[i];break;}
	}
	t=v4;ct=0;fg=0;dfs(s,0);
	for(int i=1;i<=n;i++)v3[i]=v1[i];
	for(int i=1;i<ct;i++)v3[st[i]]=v3[st[i+1]];
	v3[st[ct]]=0;
	long long as=ct-1;
	t=s2;ct=0;fg=0;dfs(s1,0);
	int ct1=0,ct2=0,fg2=-1,tp=0;
	for(int i=1;i<=ct;i++)fr2[v2[st[i]]]=i,is2[st[i]]=1;
	for(int i=1;i<=ct;i++)
	{
		if(!v3[st[i]])continue;
		int nt=fr2[v3[st[i]]];fr2[v3[st[i]]]=0;
		if(!nt){printf("-1\n");return 0;}
		int st=i-nt+(i<nt?ct:0);
		if(fg2==-1)fg2=st,ct1=1;
		else
		{
			if(fg2==st)ct1++;
			else if(fg2==st-1)ct2++;
			else if(fg2==st+1){if(ct2){printf("-1\n");return 0;}ct2=ct1;ct1=1,fg2--;}
			else if(fg2==0&&st+1==ct){if(ct2){printf("-1\n");return 0;}ct2=ct1,ct1=1,fg2=ct-1;}
			else if(st==0&&fg2==ct-1)ct2++;
			else {printf("-1\n");return 0;}
		}
	}
	for(int i=1;i<=ct;i++)v3[st[i]]=v2[st[i]];
	long long as1=1ll*ct1*fg2+1ll*ct2*(fg2+1),as2=1ll*ct1*(ct-fg2)+1ll*ct2*(ct-fg2-1);
	if(as2<as1)as1=as2;
	as+=as1;
	for(int i=1;i<=n;i++)if(fr2[v2[i]])s5=i;
	v3[s5]=0;
	t=s4;ct=0;fg=0;
	dfs(s5,0);
	for(int i=1;i<ct;i++)v3[st[i]]=v3[st[i+1]];
	v3[st[ct]]=0;
	for(int i=1;i<=n;i++)if(v2[i]!=v3[i]){printf("-1\n");return 0;}
	as+=ct-1;
	if(s1>s2)s1^=s2^=s1^=s2;
	printf("%d %d %lld\n",s1,s2,as);
}