#include<bits/stdc++.h>
using namespace std;
 
int main(){
	register int t,a,b;
	register long long s;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b),s=0;
		if(b>8)++s;
		if(b>98)++s;
		if(b>998)++s;
		if(b>9998)++s;
		if(b>99998)++s;
		if(b>999998)++s;
		if(b>9999998)++s;
		if(b>99999998)++s;
		if(b>999999998)++s;
		s*=a;
		printf("%lld\n",s);
	}
	return 0;
}//