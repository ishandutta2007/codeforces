#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
int x,ans,h,m;
bool check(){
	return ((h/10==7)||(h%10==7)||(m/10==7)||(m%10==7));
}
int main(){
	scanf("%d",&x);
	scanf("%d%d",&h,&m);

	while(1){
		if(check()) break;
		ans++;
		m-=x;
		if(m<0){
			m+=60;h--;
		}
		if(h<0) h+=24;
	}
	printf("%d\n",ans);
	return 0;
}