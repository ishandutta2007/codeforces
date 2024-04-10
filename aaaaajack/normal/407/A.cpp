#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
	int i,a,b,j,x1,x2,y1,y2;
	bool flag=false;
	map<int,int> square;
	for(i=1;i<=1000;i++) square.insert(make_pair(i*i,i));
	scanf("%d%d",&a,&b);
	for(i=1;i<a;i++){
		if(square.count(a*a-i*i)){
			x1=-i;
			y1=square[a*a-i*i];
			for(j=1;j<b;j++){
				if(square.count(b*b-j*j)){
					x2=j;
					y2=square[b*b-j*j];
					if(y1!=y2&&x1*x2+y1*y2==0) flag=true;
				}
				if(flag) break;
			}
			if(flag) break;
		}
	}
	if(flag){
		printf("YES\n");
		printf("0 0\n");
		printf("%d %d\n",x1,y1);
		printf("%d %d\n",x2,y2);
	}
	else printf("NO\n");
	return 0;
}