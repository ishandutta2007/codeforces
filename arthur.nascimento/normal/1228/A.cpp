#include <bits/stdc++.h>
using namespace std;
int mrk[11];
main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++){
		for(int j=0;j<10;j++) mrk[j] = 0;
		int u = i;
		int ok = 1;
		while(u){
			if(mrk[u%10]) ok = 0;
			mrk[u%10]++;
			u /= 10;
		}
		if(ok){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");

}