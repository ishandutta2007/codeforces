#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	if(n==2)printf("%d",m+((m&3)?((m&1)?1:2):0));
	else printf("%d",max((n*m+1)/2,max((m+2)/3*n,(n+2)/3*m)));
	return 0;
}