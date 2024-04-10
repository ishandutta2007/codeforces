#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int ans=1;
		while(n){
			ans<<=1;
			n-=n&-n;
		}
		printf("%d\n",ans);
	}
	return 0;
}