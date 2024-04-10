#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k1,k2,mx=0,x;
		int ans=-1;
		scanf("%d%d%d",&n,&k1,&k2);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x>mx){
				mx=x;
				if(i<=k1) ans=0;
				else ans=1;
			}
		}
		if(!ans) puts("YES");
		else puts("NO");
	}
	return 0;
}