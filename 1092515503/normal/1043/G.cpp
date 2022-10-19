#include<bits/stdc++.h>
using namespace std;
const int N=200100;
int n,m,LG[N];char s[N];
struct Suffix_Array{
int sa[N],rk[N],ht[N],st[18][N];
void SA(){
	static int x[N],y[N],buc[N],m;m=26;
	for(int i=0;i<m;i++)buc[i]=0;
	for(int i=0;i<n;i++)buc[x[i]=s[i]-'a']++;
	for(int i=1;i<m;i++)buc[i]+=buc[i-1];
	for(int i=n-1;i>=0;i--)sa[--buc[x[i]]]=i;
	for(int k=1;k<=n;k<<=1){
		int num=0;
		for(int i=n-k;i<n;i++)y[num++]=i;
		for(int i=0;i<n;i++)if(sa[i]>=k)y[num++]=sa[i]-k;
		for(int i=0;i<m;i++)buc[i]=0;
		for(int i=0;i<n;i++)buc[x[y[i]]]++;
		for(int i=1;i<m;i++)buc[i]+=buc[i-1];
		for(int i=n-1;i>=0;i--)sa[--buc[x[y[i]]]]=y[i];
		swap(x,y),x[sa[0]]=num=0;
		auto cmp=[&](int i,int j){
			if(y[i]!=y[j])return false;
			if(i+k<n&&j+k<n)return y[i+k]==y[j+k];
			return i+k>=n&&j+k>=n;
		};
		for(int i=1;i<n;i++)x[sa[i]]=(cmp(sa[i-1],sa[i])?num:++num);
		m=num+1;
		if(m==n)break;
	}
	for(int i=0;i<n;i++)rk[sa[i]]=i;
	for(int i=0,k=0;i<n;i++){
		if(rk[i]==0)continue;
		if(k)k--;
		for(int j=sa[rk[i]-1];j+k<n&&i+k<n&&s[j+k]==s[i+k];k++);
		ht[rk[i]]=k;
	}
	for(int i=1;i<n;i++)st[0][i]=ht[i];
	for(int j=1;j<=LG[n];j++)for(int i=1;i+(1<<j)-1<n;i++)
		st[j][i]=min(st[j-1][i],st[j-1][i+(1<<j-1)]);
}
int LCP(int x,int y){
	if(x<0||y<0||x>=n||y>=n)return 0;
	x=rk[x],y=rk[y];if(x>y)swap(x,y);x++;
	int k=LG[y-x+1];return min(st[k][x],st[k][y-(1<<k)+1]);
}
}pre,suf;
bool eql(int i,int j,int k){return pre.LCP(i,j)>=k;}
namespace Tandem{
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int lp[N],rp[N];
set<int>ls,rs;
int mn[N<<2];
void build(int x,int l,int r){
	if(l==r)mn[x]=lp[l];
	else build(lson,l,mid),build(rson,mid+1,r),mn[x]=min(mn[lson],mn[rson]);
}
int query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return n;
	if(L<=l&&r<=R)return mn[x];
	return min(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
}
void tandeminit(){
	for(int i=0;i<n;i++)lp[i]=n,rp[i]=-1,ls.insert(i),rs.insert(i);
	for(int i=1;i<=(n>>1);i++)for(int j=0;j+i<n;j+=i){
		int k=j+i;
		int l=min(pre.LCP(j,k),i),r=min(suf.LCP(n-j,n-k),i-1);
		int d=l+r-i+1;
		for(auto it=ls.lower_bound(j-r);it!=ls.end()&&*it<j-r+d;it=ls.erase(it))
			lp[*it]=*it+(i<<1)-1;
		for(auto it=rs.lower_bound(k+l-d);it!=rs.end()&&*it<k+l;it=rs.erase(it))
			rp[*it]=*it-(i<<1)+1;
	}
	build(1,0,n-1);
}
}using namespace Tandem;
namespace Repeat{
int nex[N],las[N];
void repeatinit(){
	static int buc[30];
	for(int i=0;i<26;i++)buc[i]=-1;
	for(int i=0;i<n;i++){
		las[i]=buc[s[i]-'a'];
		if(buc[s[i]-'a']!=-1)nex[buc[s[i]-'a']]=i;
		buc[s[i]-'a']=i;
	}
	for(int i=0;i<26;i++)if(buc[i]!=-1)nex[buc[i]]=n;
}
}using namespace Repeat;
namespace Solve{
bool checkrun(int l,int r){
	for(int i=1;i*i<=(r-l+1);i++)if(!((r-l+1)%i)){
		if(i==r-l+1)continue;
		if(eql(l,l+i,r-l+1-i))return true;
		int j=(r-l+1)/i;
		if(j==r-l+1)continue;
		if(eql(l,l+j,r-l+1-j))return true;
	}
	return false;
}
inline bool checktandemfix(int l,int r){return lp[l]<=r||rp[r]>=l;}
bool checkborder(int l,int r){
	const static int BBB=450;
	for(int i=1;i<=BBB;i++){
		if(l+i-1>=r-i+1)return false;
		if(eql(l,r-i+1,i))return true;
	}
	for(int i=max(pre.rk[l]-BBB,0);i<=min(pre.rk[l]+BBB,n-1);i++){
		if(pre.sa[i]<=l||pre.sa[i]>r)continue;
		int len=pre.sa[i]-l;
		if(l+len-1<r-len+1&&eql(l,r-len+1,len))return true;
		len=r-pre.sa[i]+1;
		if(l+len-1<r-len+1&&eql(l,r-len+1,len))return true;
	}
	return false;
}
inline bool checktandemid(int l,int r){return query(1,0,n-1,l,r)<=r;}
inline bool checkrepeatfix(int l,int r){return nex[l]<=r||las[r]>=l;}
bool checkrepeatmid(int l,int r){
	if(r-l+1>26)return true;
	static bool occ[30];memset(occ,false,sizeof(occ));
	for(int i=l;i<=r;i++){
		if(occ[s[i]-'a'])return true;
		occ[s[i]-'a']=true;
	}
	return false;
}
int solve(int l,int r){
//	for(int i=l;i<=r;i++)putchar(s[i]);puts("");
	if(checkrun(l,r))return 1;
	if(checktandemfix(l,r)||checkborder(l,r))return 2;
	if(checkrepeatfix(l,r)||checktandemid(l,r))return 3;
	if(checkrepeatmid(l,r))return 4;
	return -1;
}
}using namespace Solve;
namespace FIFO{
char buf[1<<23],*p1=buf,*p2=buf;
#ifndef Troverld
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#else
#define gc() getchar()
#endif
void read(int&x){
	x=0;
	char c=gc();
	while(c>'9'||c<'0')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=gc();
}
void readstr(char*s){
	char c=gc();
	while(c==' '||c=='\n')c=gc();
	while(c!=' '&&c!='\n')*s++=c,c=gc();
}
}using namespace FIFO;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	read(n),readstr(s);
	for(int i=2;i<=n;i++)LG[i]=LG[i>>1]+1;
	pre.SA(),reverse(s,s+n),suf.SA(),reverse(s,s+n);
	tandeminit(),repeatinit();
//	for(int i=0;i<n;i++)printf("%d ",lp[i]);puts("");
//	for(int i=0;i<n;i++)printf("%d ",rp[i]);puts("");
//	for(int i=0;i<n;i++)printf("%d ",nex[i]);puts("");
//	for(int i=0;i<n;i++)printf("%d ",las[i]);puts("");
	read(m);for(int i=1,l,r;i<=m;i++)read(l),read(r),printf("%d\n",solve(l-1,r-1));
	return 0;
}
/*
9
bbaacbaba
7
1 1
1 2
1 3
1 4
1 5
1 6
1 7
*/