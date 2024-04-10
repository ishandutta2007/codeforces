#include<bits/stdc++.h>
using namespace std;
int n,mx,x;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		printf("%d ",mx+x);
		mx=max(mx,mx+x);
	}
	return 0;
}