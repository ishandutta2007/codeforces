#include<bits/stdc++.h>
using namespace std;
int T,a,b;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		printf("%I64d\n",1ll*((a/b)+((a%b)>=1))*b-a);
	}
	return 0;
}