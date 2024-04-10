#include<bits/stdc++.h>
using namespace std;
int A,B,las,mx;
char a[1001],b[1001];
int main(){
	scanf("%s%s",a,b),A=strlen(a),B=strlen(b);
	for(int i=0;i<A;i++)for(int j=i;j<A;j++){
		las=0;
		for(int k=0;k<i;k++)if(a[k]==b[las])las++;
		for(int k=j+1;k<A;k++)if(a[k]==b[las])las++;
		if(las>=B)mx=max(mx,j-i+1);
	}
	printf("%d\n",mx);
	return 0;
}