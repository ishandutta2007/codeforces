/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,x[3],y[3];
void mina(){
	scanf("%d",&n);
	for(int i=0;i<3;i++)scanf("%d%d",&x[i],&y[i]);
	int X,Y,U,V;
	for(int i=0;i<3;i++){
		bool ok=true;
		for(int j=0;j<3;j++)if(abs(x[i]-x[j])+abs(y[i]-y[j])==2){ok=false;break;}
		if(ok){X=x[i],Y=y[i];break;}
	}
	scanf("%d%d",&U,&V);
	if((X==1||X==n)&&(Y==1||Y==n)){
		puts(U==X||V==Y?"YES":"NO");
		return;
	}
	puts(((U^X)&1)&&((V^Y)&1)?"NO":"YES");
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}