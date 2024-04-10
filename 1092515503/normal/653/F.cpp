#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500100;
int n,m;
namespace Suffix_Array{
	int x[N],y[N],buc[N],sa[N],rk[N],ht[N];
	char s[N];
	bool mat(int a,int b,int k){
		if(y[a]!=y[b])return false;
		if((a+k<=n)^(b+k<=n))return false;
		if((a+k<=n)&&(b+k<=n))return y[a+k]==y[b+k];
		return true;
	}
	void SA(){
		for(int i=1;i<=n;i++)buc[x[i]=s[i]]++;
		for(int i=1;i<=m;i++)buc[i]+=buc[i-1];
		for(int i=n;i;i--)sa[buc[x[i]]--]=i;
		for(int k=1;k<=n;k<<=1){
			int num=0;
			for(int i=n-k+1;i<=n;i++)y[++num]=i;
			for(int i=1;i<=n;i++)if(sa[i]>k)y[++num]=sa[i]-k;
			for(int i=0;i<=m;i++)buc[i]=0;
			for(int i=1;i<=n;i++)buc[x[y[i]]]++;
			for(int i=1;i<=m;i++)buc[i]+=buc[i-1];
			for(int i=n;i;i--)sa[buc[x[y[i]]]--]=y[i];
			swap(x,y);
			x[sa[1]]=num=1;
			for(int i=2;i<=n;i++)x[sa[i]]=mat(sa[i],sa[i-1],k)?num:++num;
			if(n==num)break;
			m=num;
		}
		for(int i=1;i<=n;i++)rk[sa[i]]=i;
		for(int i=1,k=0;i<=n;i++){
			if(rk[i]==1)continue;
			if(k)k--;
			int j=sa[rk[i]-1];
			while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k])k++;
			ht[rk[i]]=k;
		}
	}
}
using namespace Suffix_Array;
int LG[N],ST[N][20];
int RMQ(int l,int r){
	int k=LG[r-l+1];
	return min(ST[l][k],ST[r-(1<<k)+1][k]);
}
vector<int>v[N<<1];
ll res;
int main(){
	scanf("%d%s",&n,s+1),m=')',SA();
	for(int i=1;i<=n;i++)ST[i][0]=(s[i]==')'?ST[i-1][0]-1:ST[i-1][0]+1),v[ST[i][0]+n].push_back(i);
	for(int i=2;i<=n;i++)LG[i]=LG[i>>1]+1;
	for(int j=1;j<=LG[n];j++)for(int i=1;i+(1<<j)-1<=n;i++)ST[i][j]=min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n;i++){
		int l=sa[i]+ht[i]-1,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(RMQ(sa[i],mid)>=ST[sa[i]-1][0])l=mid;
			else r=mid-1;
		}
		int pos=ST[sa[i]-1][0]+n;
		res+=upper_bound(v[pos].begin(),v[pos].end(),l)-upper_bound(v[pos].begin(),v[pos].end(),sa[i]+ht[i]-1);
	}
	printf("%lld\n",res);
	return 0;
}