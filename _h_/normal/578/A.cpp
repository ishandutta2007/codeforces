#include <cstdio>
#include <cmath>
using namespace std;
typedef double ld;

int main(){
	int aa,bb;
	scanf("%d %d",&aa,&bb);
	ld a = aa, b = bb;
	if(b > a){
		puts("-1");
		return 0;
	}
	ld n = 2*floor(((a/b)-1)/2+0.00000000001)+1;
	printf("%.10lf\n",(a+b)/(n+1));
}