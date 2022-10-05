#include<bits/stdc++.h>
using namespace std;
const int N=200009;
char str[N];
int s[N],u[N],v[N],sa[N],h[N],t[N],id[N],cnt[N];
multiset<int>st;
basic_string<int>ad[N],dl[N];
long long ans[N];
int main(){
	int*rk=u,*b=v,a,o,l,r,i,j,k=0,x,y,n=0,m=N-1;
	scanf("%d%d",&a,&o);
	if(o==1){
		while(a--)scanf("%s",str+1),l=strlen(str+1),printf("%lld ",l*(l+1ll)/2);
		return 0;
	}
	for(i=1;i<=a;++i,n+=l+1,s[n]=999+i)for(scanf("%s",str+1),l=strlen(str+1),j=1;j<=l;++j)id[n+j]=i,s[n+j]=str[j];
	for(i=1;i<=n;++i)++t[rk[i]=s[i]];
	for(i=1;i<=m;++i)t[i]+=t[i-1];
	for(i=n;i;--i)sa[t[s[i]]--]=i;
	for(i=1;k<n;i*=2,m=k){
		for(memset(t,0,m*4+4),j=n-i+1,k=0;j<=n;++j)b[++k]=j;
		for(j=1;j<=n;++j)if(++t[rk[j]],sa[j]>i)b[++k]=sa[j]-i;
		for(j=1;j<=m;++j)t[j]+=t[j-1];
		for(j=n;j;--j)sa[t[rk[b[j]]]--]=b[j];
		for(j=1,swap(rk,b),k=y=0;j<=n;++j,y=x)x=sa[j],rk[x]=b[x]==b[y]&&b[x+i]==b[y+i]?k:++k;
	}
	for(i=1,k=0;i<=n;h[rk[i++]]=k)if(rk[i]>1)for(j=sa[rk[i]-1],k=max(0,k-1);s[i+k]==s[j+k];++k);
	for(l=1,r=k=0;l<=n;++l){
		while(k<o&&r<n){
			++r,st.insert(h[r]);
			if(id[sa[r]])if((++cnt[id[sa[r]]])==1)++k;
		}
		if(k<o)break;
		st.erase(st.find(h[l]));
		j=*st.begin(),ad[l]+=j,dl[r]+=j;
		if(id[sa[l]])if((--cnt[id[sa[l]]])==0)--k;
	}memset(cnt,0,sizeof cnt);
	for(l=n,r=n+1,st={},k=0;l;--l){
		while(k<o&&r>1){
			--r,st.insert(h[r+1]);
			if(id[sa[r]])if((++cnt[id[sa[r]]])==1)++k;
		}
		if(k<o)break;
		st.erase(st.find(h[l+1]));
		j=*st.begin(),ad[r]+=j,dl[l]+=j;
		if(id[sa[l]])if((--cnt[id[sa[l]]])==0)--k;
	}
	for(i=1,st={};i<=n;++i){
		for(int j:ad[i])st.insert(j);
		if(st.size())ans[id[sa[i]]]+=*st.rbegin();
		for(int j:dl[i])st.erase(st.find(j));
	}
	for(i=1;i<=a;++i)printf("%lld ",ans[i]);
	return 0;
}