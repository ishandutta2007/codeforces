#include<bits/stdc++.h>
using namespace std;
long long h,l;
int main(){
	scanf("%I64d%I64d",&h,&l);
	printf("%.10lf",1.0*((l*l)-(h*h))/2/h);
	return 0;
}