#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,z,l[200039],r[200039],ans;
char a[200039],b[200039];
int main(){
	register int i;
	scanf("%d%d",&n,&m);scanf("%s",a+1);scanf("%s",b+1);
	r[m+1]=n+1;
	for(i=m;i;i--){
		r[i]=r[i+1]-1;
		while(a[r[i]]!=b[i])
		 r[i]--;
	} 
	l[0]=0;
	for(i=1;i<=m;i++){
		l[i]=l[i-1]+1;
		while(a[l[i]]!=b[i]) l[i]++;
	}
	for(i=1;i<m;i++) ans=max(ans,r[i+1]-l[i]);
	printf("%d\n",ans);
}