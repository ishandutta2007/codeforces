#include<bits/stdc++.h>
using namespace std;
const int N=500100;
typedef long long ll;
int A,B,id[N],len[N],pos[N];
namespace Suffix_Array{
	int x[N],y[N],buc[N],sa[N],ht[N],rk[N],n,m,mn[N][20],LG[N],s[N];
	char str[N];
	bool mat(int a,int b,int k){
		if(y[a]!=y[b])return false;
		if((a+k<n)^(b+k<n))return false;
		if((a+k<n)&&(b+k<n))return y[a+k]==y[b+k];
		return true;
	}
	void SA(){
		for(int i=0;i<n;i++)buc[x[i]=s[i]]++;
		for(int i=1;i<=m;i++)buc[i]+=buc[i-1];
		for(int i=n-1;i>=0;i--)sa[--buc[x[i]]]=i;
		for(int k=1;k<n;k<<=1){
			int num=0;
			for(int i=n-k;i<n;i++)y[num++]=i;
			for(int i=0;i<n;i++)if(sa[i]>=k)y[num++]=sa[i]-k;
			for(int i=0;i<=m;i++)buc[i]=0;
			for(int i=0;i<n;i++)buc[x[y[i]]]++;
			for(int i=1;i<=m;i++)buc[i]+=buc[i-1];
			for(int i=n-1;i>=0;i--)sa[--buc[x[y[i]]]]=y[i];
			swap(x,y);
			x[sa[0]]=num=0;
			for(int i=1;i<n;i++)x[sa[i]]=mat(sa[i],sa[i-1],k)?num:++num;
			if(num>=n-1)break;
			m=num;
		}
		for(int i=0;i<n;i++)rk[sa[i]]=i;
		for(int i=0,k=0;i<n;i++){
			if(!rk[i])continue;
			if(k)k--;
			int j=sa[rk[i]-1];
			while(i+k<n&&j+k<n&&s[i+k]==s[j+k])k++;
			ht[rk[i]]=k;
		}
		for(int i=2;i<n;i++)LG[i]=LG[i>>1]+1;
		for(int i=1;i<n;i++)mn[i][0]=ht[i];
		for(int j=1;j<=LG[n-1];j++)for(int i=1;i+(1<<j)-1<n;i++)mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
	}
	int LCP(int x,int y){
		if(x>y)swap(x,y);
		x++;
		int k=LG[y-x+1];
		return min(mn[x][k],mn[y-(1<<k)+1][k]);
	}
	void Range(int x,int k,int &L,int &R){
		int l,r;
		x=rk[x];
		l=0,r=x;
		while(l<r){
			int mid=(l+r)>>1;
			if(LCP(mid,x)>=k)r=mid;
			else l=mid+1;
		}
		L=r;
		l=x,r=n-1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(LCP(mid,x)>=k)l=mid;
			else r=mid-1;
		}
		R=l;
	}
}
using namespace Suffix_Array;
struct Query{
	int x,l,r,id;
	Query(int _1=0,int _2=0,int _3=0,int _4=0){x=_1,l=_2,r=_3,id=_4;}
	friend bool operator <(const Query &x,const Query &y){
		return x.x<y.x;
	}
}q[N<<1];
int res[N],t[N];
void ADD(int x){while(x<=A)t[x]++,x+=x&-x;}
int SUM(int x){int sum=0;while(x)sum+=t[x],x-=x&-x;return sum;}
int main(){
	scanf("%d%d",&A,&B);
	for(int i=1;i<=A;i++){
		scanf("%s",str),m=strlen(str),len[i]=m,pos[i]=n;
		for(int j=0;j<m;j++)s[n]=str[j]-'a'+1,id[n]=i,n++;
		s[n++]=i+26;
	}
	m=A+26;
	SA();
	for(int i=1,a,b,c,d;i<=B;i++){
		scanf("%d%d%d",&c,&d,&a);
		Range(pos[a],len[a],a,b);
		q[i]=Query(a-1,c,d,-i);
		q[i+B]=Query(b,c,d,i);
	}
	sort(q+1,q+(B<<1)+1);
	for(int i=0,j=1;i<n;i++){
		if(id[sa[i]])ADD(id[sa[i]]);
		while(j<=(B<<1)&&q[j].x<i)j++;
		while(j<=(B<<1)&&q[j].x==i){
			int tmp=SUM(q[j].r)-SUM(q[j].l-1);
			if(q[j].id<0)res[-q[j].id]-=tmp;
			else res[q[j].id]+=tmp;
			j++;
		}
	}
	for(int i=1;i<=B;i++)printf("%d\n",res[i]);
	return 0;
}