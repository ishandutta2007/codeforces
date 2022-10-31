#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,h,m;
	scanf("%d %d:%d",&n,&h,&m);
	if(m>=60) m%=10;
	if(n==12&&(h<1||h>12)){
		if(h%10==0) h=10;
		else h%=10;
	}
	else if(n==24&&h>=24){
		h%=10;
	}
	printf("%02d:%02d\n",h,m);
	return 0;
}