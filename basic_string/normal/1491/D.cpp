#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n,u,v,a,b,i;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&u,&v),a=b=0;
		if(u>v){puts("NO");goto gg;}
		for(i=1;i<(1<<30);i*=2){
			if(u&i)++a;
			if(v&i)++b;
			if(a<b){puts("NO");goto gg;}
		}
		puts("YES");gg:;
	}
	return 0;
}