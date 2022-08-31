#include<bits/stdc++.h>
using namespace std;
const int N = 222222;
int n;
char s[N];
int main(){
	int T,i,o,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		o=0;
		for(i=1;i<=n;i++){
			if(s[i]=='1')
				o++;
		}
		if((o&1)||s[1]=='0'||s[n]=='0'){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(x=1;x>=0;x--){
			y=o/2;
			for(i=1;i<=n;i++){
				if(s[i]=='1'){
					if(y>0)
						printf("(");
					else
						printf(")");
					y--;
				}
				else{
					if(x)
						printf("(");
					else
						printf(")");
					x^=1;
				}
			}
			printf("\n");
		}
	}
	return 0;
}