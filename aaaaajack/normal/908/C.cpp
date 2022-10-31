#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,r,x[2000];
	double y[2000];
	scanf("%d%d",&n,&r);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
		y[i]=r;
		for(int j=0;j<i;j++){
			if(abs(x[i]-x[j])>2*r) continue;
			y[i]=max(y[i],y[j]+sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j])));
		}
		if(i) putchar(' ');
		printf("%.10f",y[i]);
	}
	putchar('\n');
	return 0;
}