#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui long long
#define ull unsigned long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline int rd()
{
	int x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=105;
int n,m,ans,p[N],l[N],num[N],L[N],R[N],a[N],b[N],f[N][N*3][N*3];vi V;
inline bool cmp(int x,int y){return p[x]<p[y];}
inline void cmx(int&x,int y){x=x>y?x:y;}
int main()
{
	n=rd();rep(i,1,n){p[i]=rd();l[i]=rd();num[i]=i;V.pb(p[i]-l[i]);V.pb(p[i]);V.pb(p[i]+l[i]);}
	V.pb(-1e9);sort(num+1,num+n+1,cmp);sort(V.begin(),V.end());V.erase(unique(V.begin(),V.end()),V.end());
	m=V.size()-1;rep(i,1,n)a[i]=p[num[i]],b[i]=l[num[i]];
	rep(i,1,n)
	{
		L[i]=lb(V.begin(),V.end(),a[i]-b[i])-V.begin();
		p[i]=lb(V.begin(),V.end(),a[i])-V.begin();
		R[i]=lb(V.begin(),V.end(),a[i]+b[i])-V.begin();
	}
	rep(i,1,n)
	{
		rep(j,1,m)rep(k,j,m)
		{
			cmx(f[i][j][max(R[i],k)],f[i-1][j][k]+max(0,V[R[i]]-V[k]));
			if(j>=L[i])cmx(f[i][0][max(p[i],k)],f[i-1][j][k]+max(0,V[p[i]]-V[k]));
		}
		rep(j,1,m)
		{
			if(j<p[i])
			{
				cmx(f[i][0][R[i]],f[i-1][0][j]+V[R[i]]-V[p[i]]);
				rep(k,j,p[i]-1)cmx(f[i][k][R[i]],f[i-1][0][j]+V[R[i]]-V[k]);
			}
			else
			{
				cmx(f[i][0][max(R[i],j)],f[i-1][0][j]+max(0,V[R[i]]-V[j]));
			}
			cmx(f[i][0][max(p[i],j)],f[i-1][0][j]+max(0,V[p[i]]-V[max(j,L[i])]));
			rep(k,j,L[i]-1)cmx(f[i][k][max(p[i],j)],f[i-1][0][j]+V[p[i]]-V[k]);
		}
	}
	rep(i,1,m)ans=max(ans,f[n][0][i]);
	printf("%d\n",ans);return 0;
}