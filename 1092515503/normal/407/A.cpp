#include<bits/stdc++.h>
using namespace std;
int a,b;
bool isq(int ip){
	int t=sqrt(ip);
	return t*t==ip;
}
pair<int,int>p1,p2;
bool par(int a,int b,int c,int d){
	if(a==c)return false;
	if(b==d)return false;
	return true;
}
int main(){
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)if(isq(a*a-i*i)){
		int x=i,y=sqrt(a*a-i*i),gcd=__gcd(x,y);
		if(b%(a/gcd))continue;
		if(par(x,y,-y*b/a,x*b/a)){printf("YES\n%d %d\n%d %d\n%d %d\n",0,0,x,y,-y*b/a,x*b/a);return 0;}
		if(par(y,x,-x*b/a,y*b/a)){printf("YES\n%d %d\n%d %d\n%d %d\n",0,0,y,x,-x*b/a,y*b/a);return 0;}
	}
	puts("NO");
	return 0;
}