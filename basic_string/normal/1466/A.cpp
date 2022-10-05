#include<bits/stdc++.h>
using namespace std;
int a[99];
set<int>st;
int main(){
	int T,n,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);st.clear();
		for(i=1;i<=n;++i)scanf("%d",a+i);
		for(i=1;i<=n;++i)for(j=1;j<i;++j)st.insert(a[j]-a[i]);
		cout<<st.size()<<'\n';
	}
	return 0;
}