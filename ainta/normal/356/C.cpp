#include<stdio.h>
#include<algorithm>
using namespace std;
int n,a,C[5],S,j,mm,Res;
int main()
{
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		C[a]++;
		S+=a;
	}
	if(S<3 || S==5){printf("-1\n");return 0;}
	mm=C[1]<C[2]?C[1]:C[2];
	C[1]-=mm,C[2]-=mm,C[3]+=mm,Res+=mm;
	Res+=(C[1]+C[2])/3*2;
	if(C[1])C[3]+=C[1]/3;
	else C[3]+=C[2]/3*2;
	C[1]%=3,C[2]%=3;
	if(C[1]==1 && !C[3])Res+=2;
	else Res+=C[1];
	if(C[2]==1 && !C[4])Res+=2;
	else Res+=C[2];
	printf("%d\n",Res);
}