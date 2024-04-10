#include <bits/stdc++.h>
using namespace std;
const int INF=1e4;
void get_min(int &x,int y){
	if(x>y) x=y;
}
int n;
int a[2050];
int b[2050];
bool check(){
	for(int i=1;i<n;++i) if(b[i]>b[i+1]) return 0;
	return 1;
}
void upd1(){
	for(int i=1;i<=n;i+=2){
		swap(b[i],b[i+1]);
	}
	return;
}
void upd2(){
	int m=n/2;
	for(int i=1;i<=m;++i){
		swap(b[i],b[i+m]);
	}
	return;
}
void MAIN(){
	int ans=INF;
	scanf("%d",&n);
	n=n+n;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) b[i]=a[i];
	if(check()){
		puts("0");
		return;
	}
	for(int tt=1;tt<=n;++tt){
		if(tt&1){
			upd2();
		}
		else{
			upd1();
		}
		if(check()) ans=min(ans,tt);
	}
	for(int tt=1;tt<=n;++tt){
		if(tt&1){
			upd1();
		}
		else{
			upd2();
		}
		if(check()) ans=min(ans,tt);
	}
	if(ans==INF) puts("-1");
	else printf("%d\n",ans);
	return;
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--) MAIN();
    return 0;
}