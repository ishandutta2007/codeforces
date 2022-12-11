#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10000],ans,lft,al,ar,nouse=999999999999999;
int cal(int l,int r,int np){
	if(l>r) return 0;
	if(l==r){
		if(a[l]==0) return 0;
		a[l]=0;
		return 1;
	}
	int tg=999999999999999;
	for(int i=l;i<=r;i++) tg=min(tg,a[i]);
	for(int i=l;i<=r;i++) a[i]-=tg;
	int ng=0,lg=l;
	for(int i=l-1;i<=r;i++){
		if(a[i+1]==0){
			ng+=cal(lg,i,np+1);
			lg=i;
			while(a[lg]==0&&lg<=r) lg++;
		}
	}
	if(r-l+1<ng+1){
		for(int i=l;i<=r;i++) a[i]=0;
	}
	return min(r-l+1,ng+tg);
}
signed main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nouse=min(nouse,a[i]);
	}
	printf("%d\n",cal(1,n,0));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5
2 1 2 2 1
*/