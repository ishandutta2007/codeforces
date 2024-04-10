#include<cstdio>
using namespace std;
int n,a;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(a==1) printf("-1\n");
		else{
			putchar('2');
			a--;
			while(a--) putchar('3');
			putchar('\n');
		}
	}
}