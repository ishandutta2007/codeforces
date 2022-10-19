#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100100;
int n,m;
int x[N],y[N],buc[N],sa[N],ht[N],rk[N];
char s[N];
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
}
int stk[N],L[N],R[N],tp,lson[N],rson[N],rt;
ll res;
void solve(int x,int las){
	res+=1ll*(ht[x]-las)*(R[x]-L[x])*(R[x]-L[x]+1)/2;
	if(lson[x])solve(lson[x],ht[x]);
	else res+=(n-sa[L[x]])-ht[x];
	if(rson[x])solve(rson[x],ht[x]);
	else res+=(n-sa[R[x]-1])-ht[x];
}
int main(){
	scanf("%s",s),n=strlen(s),m='z';
	SA();
	for(int i=1;i<n;i++){
		while(tp&&ht[stk[tp]]>ht[i])lson[i]=stk[tp],R[stk[tp]]=i,tp--;
		if(tp)rson[stk[tp]]=i;
		L[i]=stk[tp],stk[++tp]=i;
	}
	while(tp)R[stk[tp--]]=n;
	rt=stk[1];
	solve(rt,0);
	printf("%lld\n",res);
	return 0;
}