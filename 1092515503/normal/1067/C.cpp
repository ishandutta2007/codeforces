#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n<=10){for(int i=1;i<=n;i++)printf("%d %d\n",1,i);return 0;}
	for(int i=1;i<=3;i++)printf("%d %d\n",1,i);
	n-=6;
	int i=2;
	for(int tp=(n%3==2);n;i++,tp^=1){
		if(tp)printf("%d %d\n%d %d\n",i,1,i,3),n-=2;
		else printf("%d %d\n",i,2),n--;
	}
	for(int j=1;j<=3;j++)printf("%d %d\n",i,j);
	return 0;
}