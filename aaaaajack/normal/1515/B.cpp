#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a=round(sqrt(n*0.25)),b=round(sqrt(n*0.5));
		if(a*a*4==n || b*b*2==n){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}