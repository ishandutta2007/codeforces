/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
const int N=101000;
int n,m,q,P[N],S[N],_n,_m,s[N<<1];
char t[N];
namespace SA{
int sa[N<<1],rk[N<<1];
void SAinit(){
	static int x[N<<1],y[N<<1],buc[N<<1];
	for(int i=0;i<_n;i++)buc[x[i]=s[i]]++;
	for(int i=1;i<_m;i++)buc[i]+=buc[i-1];
	for(int i=_n-1;i>=0;i--)sa[--buc[x[i]]]=i;
	for(int k=1;k<=_n;k<<=1){
		int num=0;
		for(int i=_n-k;i<_n;i++)y[num++]=i;
		for(int i=0;i<_n;i++)if(sa[i]>=k)y[num++]=sa[i]-k;
		for(int i=0;i<_m;i++)buc[i]=0;
		for(int i=0;i<_n;i++)buc[x[y[i]]]++;
		for(int i=1;i<_m;i++)buc[i]+=buc[i-1];
		for(int i=_n-1;i>=0;i--)sa[--buc[x[y[i]]]]=y[i],y[i]=0;
		swap(x,y),x[sa[0]]=num=0;
		auto cmp=[&](const int&i,const int&j){
			if(y[i]!=y[j])return false;
			if(i+k<_n&&j+k<_n)return y[i+k]==y[j+k];
			return i+k>=_n&&j+k>=_n;
		};
		for(int i=1;i<_n;i++)x[sa[i]]=(cmp(sa[i-1],sa[i])?num:++num);
		_m=num+1;
		if(_m==_n)break;
	}
	for(int i=0;i<_n;i++)rk[sa[i]]=i;
}
}
namespace HS{
const int M=2;
int pov[M][N<<1],vop[M][N<<1];
int ksm(int x,int y,int mod){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int inversion(int x,int mod){return ksm(x,mod-2,mod);}
const int mod[M]={666623333,998244353};
const int bs=300007;
struct Hash{
int val[M],len;
Hash(){memset(val,0,sizeof(val)),len=0;}
Hash(int c){for(int i=0;i<M;i++)val[i]=c;len=1;}
void print()const{putchar('[');for(int i=0;i<M;i++)printf("%d%c",val[i],i==2?']':',');printf("%d\n",len);}
friend Hash operator+(const Hash&u,const Hash&v){
	Hash w;w.len=u.len+v.len;
	for(int i=0;i<M;i++)w.val[i]=(1ll*u.val[i]*pov[i][v.len]+v.val[i])%mod[i];
	// u.print(),puts("+"),v.print(),puts("="),w.print();
	return w;
}
friend Hash operator-(const Hash&u,const Hash&v){//here, v=u in plus function.
	Hash w;w.len=u.len-v.len;
	for(int i=0;i<M;i++)w.val[i]=(u.val[i]+mod[i]-1ll*v.val[i]*pov[i][w.len]%mod[i])%mod[i];
	return w;
}
friend Hash operator/(const Hash&u,const Hash&v){//here, v=v in plus function.
	Hash w;w.len=u.len-v.len;
	for(int i=0;i<M;i++)w.val[i]=1ll*(u.val[i]+mod[i]-v.val[i])*vop[i][v.len]%mod[i];
	return w;
}
friend bool operator==(const Hash&u,const Hash&v){
	if(u.len!=v.len)return false;
	for(int i=0;i<M;i++)if(u.val[i]!=v.val[i])return false;
	return true;
}
friend bool operator!=(const Hash&u,const Hash&v){
	if(u.len!=v.len)return true;
	for(int i=0;i<M;i++)if(u.val[i]!=v.val[i])return true;
	return false;
}
}sh[N<<1];
void HSinit(){
	for(int i=0;i<M;i++){
		pov[i][0]=vop[i][0]=1;
		int POV=bs,VOP=inversion(bs,mod[i]);
		// printf("<%d,%d>\n",POV,VOP);
		for(int j=1;j<=_n;j++)pov[i][j]=1ll*pov[i][j-1]*POV%mod[i],vop[i][j]=1ll*vop[i][j-1]*VOP%mod[i];
		// for(int j=0;j<=_n;j++)printf("[%d,%d]",pov[i][j],vop[i][j]);puts("");
	}
	for(int i=0;i<_n;i++)sh[i+1]=sh[i]+s[i];
}
Hash sechash(int l,int r){return sh[r]-sh[l];}
bool checklcp(int p,Hash hs){
	// printf("%d:%d\n",p,SA::rk[p]);
	// sechash(p,p+hs.len).print();
	return sechash(p,p+hs.len)==hs;
}
void getsec(int p,Hash hs,int&L,int&R){
	// printf("%d:\n",p);
	// hs.print();
	int l=0,r=p;
	while(l<r){
		int mid=(l+r)>>1;
		if(checklcp(SA::sa[mid],hs))r=mid;else l=mid+1;
	}
	L=l;
	l=p,r=_n-1;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(checklcp(SA::sa[mid],hs))l=mid;else r=mid-1;
	}
	R=r;
	// printf("[%d,%d]\n",L,R);
}
}
namespace TR{
int head[N],cnt,fa[N],son[N],sz[N],dep[N],dfn[N],rev[N],top[N],val[N],tot;
HS::Hash dw[N],up[N];
struct edge{int to,next,val;}edge[N<<1];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
}
void dfs_init(int x){
	// printf("%d:\n",x);
	// up[x].print(),dw[x].print();
	sz[x]=1;
	for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=fa[x]){
		val[y]=edge[i].val,dw[y]=dw[x]+edge[i].val,up[y]=edge[i].val+up[x],dep[y]=dep[x]+1,fa[y]=x;
		dfs_init(y);
		sz[x]+=sz[y];if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs_part(int x){
	dfn[x]=++tot,rev[tot]=x;
	if(!top[x])top[x]=x;
	if(son[x])top[son[x]]=top[x],dfs_part(son[x]);
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa[x]&&edge[i].to!=son[x])dfs_part(edge[i].to);
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
HS::Hash path(int x,int y){int z=LCA(x,y);return (up[x]/up[z])+(dw[y]-dw[z]);}
bool cmp(int x,int y,int id){
	// printf("GUGUGU:%d,%d\n",id,SA::rk[id]);
	int z=LCA(x,y);
	HS::Hash pat;int len=0;
	while(true){
		int X=fa[top[x]];
		if(top[x]==top[z])X=z;
		// printf("%d->%d\n",x,X);
		// (pat+(up[x]/up[X])).print();
		// HS::sechash(id,id+len+dep[x]-dep[X]).print();
		if(pat+(up[x]/up[X])==HS::sechash(id,id+len+dep[x]-dep[X])){
			pat=pat+(up[x]/up[X]),len+=dep[x]-dep[X];
			if(top[x]==top[z])break;
			x=X;
			continue;
		}
		int l=dfn[top[x]],r=dfn[x];
		if(top[x]==top[z])l=dfn[z]+1;
		while(l!=r){
			int mid=(l+r)>>1;
			// printf("<%d:%d>\n",mid,rev[mid]);
			// up[x].print(),up[rev[mid]].print();
			// (pat+(up[x]/up[rev[mid]])).print();
			// HS::sechash(id,id+len+dfn[x]-mid).print();
			if(pat+(up[x]/up[rev[mid]])==HS::sechash(id,id+len+dfn[x]-mid))r=mid;
			else l=mid+1;
		}
		// printf("%d:[%d,%d]\n",rev[l],dfn[x],l);
		return val[rev[l]]<s[id+len+dfn[x]-l];
	}
	vector<int>v;
	v.push_back(y);
	while(top[y]!=top[z])y=fa[top[y]],v.push_back(y);
	v.push_back(z);reverse(v.begin(),v.end());
	// printf("CHECK:%d\n",id);
	// for(auto x:v)printf("%d ",x);puts("");
	for(int i=0;i+1<(int)v.size();i++){
		int j=v[i],k=v[i+1];
		if(pat+(dw[k]-dw[j])==HS::sechash(id,id+len+dep[k]-dep[j]))
			{pat=pat+(dw[k]-dw[j]),len+=dep[k]-dep[j];continue;}
		// printf("FAIL:%d->%d\n",j,k);
		int l=dfn[top[k]],r=dfn[k];
		if(!i)l=dfn[j]+1;
		while(l!=r){
			int mid=(l+r)>>1;
			// (pat+(dw[rev[mid]]-dw[j])).print();
			// HS::sechash(id,id+len+dep[rev[mid]]-dep[j]).print();
			if(pat+(dw[rev[mid]]-dw[j])==HS::sechash(id,id+len+dep[rev[mid]]-dep[j]))l=mid+1;else r=mid;
		}
		// printf("%d\n",rev[r]);
		return val[rev[r]]<s[id+len+dep[rev[r]]-dep[j]-1];
	}
	return true;
}
void TRinit(){
	memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d%s",&x,&y,t),ae(x,y,t[0]-'a');
}
}
int bit[N<<1],res[N];
void ADD(int x){x++;while(x<=_n)bit[x]++,x+=x&-x;}
int SUM(int x){x++;int y=0;while(x)y+=bit[x],x-=x&-x;return y;}
struct dat{int l,r,id;dat(int L,int R,int ID){l=L,r=R,id=ID;}};
vector<dat>v[N];
int main(){
	scanf("%d%d%d",&n,&m,&q),TR::TRinit();
	_m=26;
	for(int i=1;i<=m;i++){
		scanf("%s",t);
		while(t[S[i]])s[_n++]=t[S[i]++]-'a';
		s[_n++]=_m++,P[i+1]=_n;
	}
	HS::HSinit(),SA::SAinit();
	TR::dfs_init(1),TR::dfs_part(1);
	// for(int i=0;i<_n;i++)printf("%d ",s[i]);puts("");
	// for(int i=0;i<_n;i++){printf("%d:",i);for(int j=SA::sa[i];j<_n;j++)printf("%d ",s[j]);puts("");}
	for(int i=1,x,y,l,r;i<=q;i++){
		scanf("%d%d%d%d",&x,&y,&l,&r);
		int L=-1,R=_n-1;
		while(L<R){
			int mid=(L+R+1)>>1;
			if(TR::cmp(x,y,SA::sa[mid]))R=mid-1;else L=mid;
		}
		// printf("PP:%d\n",L);
		HS::Hash pat=TR::path(x,y);
		if(L!=-1&&HS::checklcp(SA::sa[L],pat))HS::getsec(L,pat,L,R);
		else if(L!=_n-1&&HS::checklcp(SA::sa[L+1],pat))HS::getsec(L+1,pat,L,R);
		else continue;
		// printf("%d:[%d,%d][%d,%d]\n",i,L,R,l,r);
		v[l-1].emplace_back(L,R,-i);
		v[r].emplace_back(L,R,i);
	}
	for(int i=1;i<=m;i++){
		for(int j=P[i];j<P[i]+S[i];j++)ADD(SA::rk[j]);
		for(auto x:v[i])if(x.id>0)res[x.id]+=SUM(x.r)-SUM(x.l-1);else res[-x.id]-=SUM(x.r)-SUM(x.l-1);
	}
	for(int i=1;i<=q;i++)printf("%d\n",res[i]);
	return 0;
}
/*
9 5 1
1 2 a
2 7 c
1 3 b
3 4 b
4 6 b
3 5 a
5 8 b
5 9 c
ababa
cabbb
bac
bbbac
abacaba
5 7 3 5
*/