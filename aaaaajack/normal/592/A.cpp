#include<cstdio>
#include<algorithm>
using namespace std;
char s[10][10];
int main(){
	int a=8,b=8;
	for(int i=0;i<8;i++) scanf("%s",s[i]);
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(s[j][i]=='B') break;
			else if(s[j][i]=='W'){
				a=min(a,j);
				break;
			}
		}
		for(int j=7;j>=0;j--){
			if(s[j][i]=='W') break;
			else if(s[j][i]=='B'){
				b=min(b,7-j);
				break;
			}
		}
	}
	if(a<=b) puts("A");
	else puts("B");
	return 0;
}