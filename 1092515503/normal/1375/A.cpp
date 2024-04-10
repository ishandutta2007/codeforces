#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1,x;i<=n;i++)scanf("%d",&x),printf("%d ",i&1?abs(x):-abs(x));
		puts("");
	}
	return 0;
}