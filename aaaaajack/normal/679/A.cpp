#include<bits/stdc++.h>
using namespace std;
const int p[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int main(){
	char s[4][10],t[10];
	int yc=0,r=0;
	for(int i=0;i<4;i++){
		printf("%d\n",p[i]);
		fflush(stdout);
		scanf("%s",s[i]);
		if(s[i][0]=='y'){
			r=i;
			yc++;
		}
	}
	if(yc==0) puts("prime");
	else if(yc>1) puts("composite");
	else{
		bool gg=false;
		for(int i=r;i<15;i++){
			if(p[r]*p[i]<=100){
				printf("%d\n",p[r]*p[i]);
				fflush(stdout);
				scanf("%s",t);
				if(t[0]=='y') gg=true;
			}
		}
		if(gg) puts("composite");
		else puts("prime");
	}
	return 0;
}