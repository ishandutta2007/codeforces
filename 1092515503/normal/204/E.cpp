#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200100;
int n,m,id[N],A,B,len[N];
int x[N],y[N],buc[N],sa[N],ht[N],rk[N],s[N];
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
}
int lft[N],occ[N];
int L[N],R[N],lson[N],rson[N],stk[N],tp;
int diff[N];
ll res[N];
void solve(int x,int las){
//	printf("%d:[%d,%d]:%d-%d\n",x,L[x],R[x],las,ht[x]);
	int tmp;
	if(L[x]<=lft[R[x]-1])tmp=ht[x]-las,diff[L[x]]+=tmp,diff[R[x]]-=tmp/*,printf("A:%d:[%d,%d]:%d\n",x,L[x],R[x]-1,tmp)*/;
	if(lson[x])solve(lson[x],ht[x]);
	else if(B==1)tmp=len[sa[L[x]]]-ht[x],diff[L[x]]+=tmp,diff[L[x]+1]-=tmp/*,printf("B:%d:[%d,%d]:%d\n",x,L[x],L[x],tmp)*/;
	if(rson[x])solve(rson[x],ht[x]);
	else if(B==1)tmp=len[sa[R[x]-1]]-ht[x],diff[R[x]-1]+=tmp,diff[R[x]]-=tmp/*,printf("C:%d:[%d,%d]:%d\n",x,R[x]-1,R[x]-1,tmp)*/;
}
int main(){
	scanf("%d%d",&A,&B);
	for(int i=1;i<=A;i++){
		scanf("%s",str),m=strlen(str);
		for(int j=0;j<m;j++)s[n]=str[j]-'a'+1,id[n]=i,len[n]=m-j,n++;
		s[n++]=i+26;
	}
//	for(int i=0;i<n;i++)printf("%2d ",s[i]);puts("");
	m=A+26;
	SA();
//	for(int i=0;i<n;i++)printf("%2d ",sa[i]);puts("");
//	for(int i=0;i<n;i++)printf("%d ",id[sa[i]]);puts("");
//	for(int i=0;i<n;i++)printf("%d ",ht[i]);puts("");
	for(int i=0,j=0,k=0;j<n;j++){
		if(id[sa[j]])k+=!occ[id[sa[j]]]++;
		for(;k>=B;i++)if(id[sa[i]])k-=!--occ[id[sa[i]]];
		lft[j]=i-1;
	}
//	for(int i=0;i<n;i++)printf("%d ",lft[i]);puts("");
	for(int i=1;i<n;i++){
		while(tp&&ht[stk[tp]]>ht[i])lson[i]=stk[tp],R[stk[tp]]=i,tp--;
		if(tp)rson[stk[tp]]=i;
		L[i]=stk[tp],stk[++tp]=i;
	}
	while(tp)R[stk[tp--]]=n;
//	for(int i=1;i<n;i++)printf("[%d,%d]",L[i],R[i]);puts("");
	solve(stk[1],0);
	for(int i=1;i<n;i++)diff[i]+=diff[i-1];
//	for(int i=0;i<n;i++)printf("%d ",diff[i]);puts("");
	for(int i=0;i<n;i++)if(id[sa[i]])res[id[sa[i]]]+=diff[i];
	for(int i=1;i<=A;i++)printf("%lld ",res[i]);
	return 0;
}
/*
5 4
abababbbb
ababaaab
ababaab
ababab
abbabbabb
*/