#include<cstdio>
#define myabs(a) ((a)>0?(a):-(a))
using namespace std;
int main(){
	int r1,c1,r2,c2;
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	int rook=((r1==r2)?0:1)+((c1==c2)?0:1);
	int bishop=((r1+c1)%2==(r2+c2)%2)?(((r1+c1==r2+c2)||(r1-c1==r2-c2))?1:2):0;
	int king=myabs(r1-r2)>myabs(c1-c2)?myabs(r1-r2):myabs(c1-c2);
	printf("%d %d %d\n",rook,bishop,king);
	return 0;
}