#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	if(x1<=x2&&y1<=y2){
		puts("Polycarp");
	}
	else if(x1+y1<=x2+y2-min(x2,y2)){
		puts("Polycarp");
	}
	else{
		puts("Vasiliy");
	}
	return 0;
}