#include<bits/stdc++.h>
using namespace std;
int n,a[100100],s[200100],m,N,sa[200100],ht[200100],rk[200100],buc[200100],st[200100][20],LG[200100];
vector<int>v;
void SA(){
	for(int i=1;i<=N;i++)buc[rk[i]=s[i]]++;
	for(int i=1;i<=m;i++)buc[i]+=buc[i-1];
	for(int i=N;i;i--)sa[buc[rk[i]]--]=i;
	for(int k=1;k<=N;k<<=1){
		int num=0;
		for(int i=N-k+1;i<=N;i++)ht[++num]=i;
		for(int i=1;i<=N;i++)if(sa[i]>k)ht[++num]=sa[i]-k;
		for(int i=1;i<=m;i++)buc[i]=0;
		for(int i=1;i<=N;i++)buc[rk[ht[i]]]++;
		for(int i=1;i<=m;i++)buc[i]+=buc[i-1];
		for(int i=N;i;i--)sa[buc[rk[ht[i]]]--]=ht[i],ht[i]=0;
		swap(ht,rk),rk[sa[1]]=num=1;
		for(int i=2;i<=N;i++)rk[sa[i]]=(ht[sa[i]]==ht[sa[i-1]]&&ht[sa[i]+k]==ht[sa[i-1]+k]?num:++num);
		m=num;
		if(num==N)break;
	}
	for(int i=1;i<=N;i++)ht[i]=0;
	for(int i=1,k=0;i<=N;i++){
		if(rk[i]==1)continue;
		if(k)k--;
		int j=sa[rk[i]-1];
		while(i+k<=N&&j+k<=N&&s[i+k]==s[j+k])k++;
		ht[rk[i]]=k;
	}
	for(int i=2;i<=N;i++)LG[i]=LG[i>>1]+1;
	for(int i=1;i<=N;i++)st[i][0]=ht[i];
	for(int j=1;j<=LG[N];j++)for(int i=1;i+(1<<j)-1<=N;i++)st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int LCP(int x,int y){//the LCP between two suffixes, ranked x and y in the sa array.
	if(x>y)swap(x,y);
	x++;
	int k=LG[y-x+1];
	return min(st[x][k],st[y-(1<<k)+1][k]);
}
void range(int l,int r,int &L,int &R){
	int x=rk[n+l],len=r-l;
	l=1,r=x;
	while(l<r){
		int mid=(l+r)>>1;
		if(LCP(mid,x)>=len)r=mid;
		else l=mid+1;
	}
	L=r;
	l=x,r=N;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(LCP(mid,x)>=len)l=mid;
		else r=mid-1;
	}
	R=l;
}

#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int sum[400100];
void modify(int x,int l,int r,int P){
	if(l>P||r<P)return;
	sum[x]++;
	if(l!=r)modify(lson,l,mid,P),modify(rson,mid+1,r,P);
}
int query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return 0;
	if(L<=l&&r<=R)return sum[x];
	return query(lson,l,mid,L,R)+query(rson,mid+1,r,L,R);
}

int ql[100100],qr[100100],res[100100];
vector<int>u[200100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)s[i]=a[i+1]-a[i],s[n+i]=-s[i],v.push_back(s[i]),v.push_back(s[n+i]);
	sort(v.begin(),v.end()),v.resize(m=unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<n;i++)s[i]=lower_bound(v.begin(),v.end(),s[i])-v.begin()+1,s[n+i]=lower_bound(v.begin(),v.end(),s[n+i])-v.begin()+1;
	s[n]=++m,N=2*n-1,SA();
//	for(int i=1;i<=N;i++)printf("%2d ",i);puts("");
//	for(int i=1;i<=N;i++)printf("%2d ",s[i]);puts("");
//	for(int i=1;i<=N;i++)printf("%2d ",sa[i]);puts("");
//	for(int i=1;i<=N;i++)printf("%2d ",rk[i]);puts("");
	scanf("%d",&m);
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		if(l==r){res[i]=n-1;continue;}
		int L,R;range(l,r,L,R);
		u[L-1].push_back(-i),u[R].push_back(i);
		ql[i]=l-(r-l+1),qr[i]=r+1;
//		printf("%d %d %d %d\n",L,R,ql[i],qr[i]);
	}
	for(int i=1;i<=N;i++){
		if(sa[i]<n)modify(1,1,n,sa[i]);
		for(auto x:u[i]){
			int now=query(1,1,n,1,ql[abs(x)])+query(1,1,n,qr[abs(x)],n);
			if(x>0)res[x]+=now;
			else res[-x]-=now;
		}
	}
	for(int i=1;i<=m;i++)printf("%d\n",res[i]);
	return 0;
}