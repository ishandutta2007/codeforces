/*
	Templates start.
	Powered by c++11.
	Author : Alex_Wei.
*/

//#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

// IO templates.

char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#ifdef __WIN64
	#define gc getchar()
#else
	#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#endif
#define pc(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)

inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

/*
	Templates end.
	Please give me more points.
*/

const int N=5e5+5;

vector <int> buc[N];
ll n,m,a[N],b[N],p[N],f[N],c[N];
void modify(int x,int v){while(x<=n)c[x]+=v,x+=x&-x;}
ll query(int x){ll ans=0; while(x)ans+=c[x],x-=x&-x; return ans;}
ll cal(int l,int r){return query(r)-query(l-1);}

int main(){
	n=read()+1,mem(f,0x3f),f[0]=0;
	for(int i=1;i<n;i++)a[i]=read(),buc[a[i]].pb(i);
	buc[0].pb(0),buc[n].pb(n);
	for(int i=1;i<n;i++)p[i]=read(),modify(i,p[i]);
	b[m=read()+1]=n; for(int i=1;i<m;i++)b[i]=read();
	
	for(int i=1;i<=m;i++){
		if(i>1)for(int j=b[i-2]+1;j<=b[i-1];j++)
			for(int k:buc[j])if(p[k]>0)modify(k,-p[k]);
		int pos=-1,sz=buc[b[i-1]].size()-1;
		for(int j=0;j<buc[b[i]].size();j++){
			int k=buc[b[i]][j];
			if(j)f[k]=f[buc[b[i]][j-1]]+cal(buc[b[i]][j-1],k-1);
			while(pos<sz&&buc[b[i-1]][pos+1]<k){
				int l=buc[b[i-1]][++pos];
				f[k]=min(f[k],f[l]+cal(l+1,k-1));
			}
		}
	}
	if(f[n]<1e16)printf("YES\n%lld\n",f[n]);
	else puts("NO");
	
	return 0;
}