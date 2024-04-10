#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,a[2000039],x,y,head,ans,tot,pus;
int main(){
	register int i;
	scanf("%d",&n);////
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	ans=1;
	for(i=2;i<=n;i++){
		if(a[i]==a[i-1]) ans++;
		else{if(tot<ans) tot=ans;ans=1;}
	}
	tot=tot>ans?tot:ans;
	printf("%d\n",tot);
}