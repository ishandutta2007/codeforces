//CF 983A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
LL gcd(LL x,LL y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int main()
{
	int T;
	LL a,b,c,d;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		d=gcd(a,b);
		a/=d,b/=d;
		do{
			d=gcd(b,c);
			while(d>1&&b%d==0){
				b/=d;
			}
		}while(d>1);
		if(b==1)
			cout<<"Finite\n";
		else
			cout<<"Infinite\n";
	}
	return 0;
}