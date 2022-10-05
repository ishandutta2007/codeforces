#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp;
int a[2000009];
int main(){
	int T,n,i,j,k,u,v,w,m;
	scanf("%d",&T);
	while(T--){
		mp.clear();
		scanf("%d",&n),m=0;
		for(i=1;i<=n;++i){
			scanf("%d",&j);
			if(!mp[j])mp[j]=++m,a[m]=0;
			++a[mp[j]];
		}
		sort(a+1,a+m+1);
		for(i=a[1];;--i){
			k=0;
			for(j=1;j<=m;++j){
				u=a[j]%i,v=a[j]/i;
				if(v<u)break;
				v-=u,w=v/(i+1),v-=(i+1)*w,u+=i*w,k+=u+v;
			}
			if(j>m){
				printf("%d\n",k);
				break;
			}
		}
	}
	return 0;
}