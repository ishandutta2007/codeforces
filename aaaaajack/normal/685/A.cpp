#include<bits/stdc++.h>
bool u[7];
int a[7];
int ans,d1,d2,n,m;
inline void check(){
	long long l=0,r=0;
	for(int i=0;i<d1;i++) l=l*7+a[i];
	for(int i=d1;i<d1+d2;i++) r=r*7+a[i];
	if(l<n&&r<m) ans++;
}
void cal(int now){
	if(now==d1+d2){
		check();
		return;
	}
	for(int i=0;i<7;i++){
		if(!u[i]){
			u[i]=true;
			a[now]=i;
			cal(now+1);
			u[i]=false;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=n-1;i;i/=7) d1++;
	for(int i=m-1;i;i/=7) d2++;
	if(!d1) d1++;
	if(!d2) d2++;
	if(d1+d2>7) puts("0");
	else{
		cal(0);
		printf("%d\n",ans);
	}
	return 0;
}