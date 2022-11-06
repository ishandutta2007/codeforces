#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("%d\n",max(abs(x1-x2),abs(y1-y2)));
}