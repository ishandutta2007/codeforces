#include <cstdio>

using namespace std;

int check(int x){
	for(int a=0;a<=33;a++)
		for(int b=0;b<=14;b++)
			if(3*a+7*b==x) return 1;
	return 0;
}

int main(){
	int n,x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		printf(check(x)?"YES\n":"NO\n");
	}
	return 0;
}