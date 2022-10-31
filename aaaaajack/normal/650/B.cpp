#include<bits/stdc++.h>
#define N 500100
using namespace std;
char s[N];
int x[N];
inline int cal_dis(int l,int r,int n){
	return (n-l)+r+min(r,n-l);
}
int main(){
	int n,a,b,T,ans=0,l,r=0;
	scanf("%d%d%d%d",&n,&a,&b,&T);
	l=n-1;
	scanf("%s",s);
	for(int i=0;i<n;i++){
		if(s[i]=='h') x[i]=1;
		else x[i]=b+1;
	}
	int now=0;
	while(r<n&&now+x[r]+r*a<=T) now+=x[r++];
	while(r>0){
		--r;
		while(l>r&&now+x[l]+cal_dis(l,r,n)*a<=T){
			now+=x[l--];
		}
		now-=x[r];
		if(r+(n-l)>ans) ans=r+n-l;
	}
	printf("%d\n",ans);
	return 0;
}