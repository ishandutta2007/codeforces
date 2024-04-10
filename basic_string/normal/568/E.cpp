#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int a[N],b[N],f[N],p[N];
unordered_multiset<int>st;
basic_string<int>v[N];
int main(){
	int n,m,i,j,k,l=0,t=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	scanf("%d",&m),a[++n]=2e9;
	for(i=1;i<=m;++i)scanf("%d",b+i),st.insert(b[i]);
	sort(b+1,b+m+1);
	for(i=1;p[i]=l,i<=n;t=f[t+1]?t+1:t,++i)if(~a[i])j=lower_bound(f+1,f+t+1,a[i])-f,v[j]+=i,f[j]=a[i];else{
		for(j=m,k=t,l=i;j;f[k+1]=b[j--])while(b[j]<=f[k])--k;
	}
	for(i=n;--t;)if(j=lower_bound(v[t].begin(),v[t].end(),i)-v[t].begin()-1,j>=0&&a[k=v[t][j]]<a[i])i=k;
	else st.erase(st.find(a[p[i]]=b[lower_bound(b+1,b+m+1,a[i])-b-1])),i=p[i];
	for(i=1;i<n;++i)if(~a[i])printf("%d ",a[i]);else printf("%d ",*st.begin()),st.erase(st.begin());
	return 0;
}