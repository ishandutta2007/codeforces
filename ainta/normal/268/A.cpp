#include<stdio.h>
#include<algorithm>
using namespace std;
int n,i,j,w[31][2],c;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&w[i][0],&w[i][1]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)continue;
			if(w[i][0]==w[j][1])c++;
		}
	}
	printf("%d\n",c);
}