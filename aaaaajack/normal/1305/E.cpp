#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,big=10000;
	int a[5010];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		if(m<=(i-1)/2){
			a[i]=(i-2*m)+(i-1);
			m=0;
			i++;
			while(i<=n){
				a[i]=big*(big+i);
				i++;
			}
		}
		else{
			m-=(i-1)/2;
			a[i]=i;
		}
	}
	if(m>0) puts("-1");
	else{
		for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	}
	return 0;
}