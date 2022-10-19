#include<bits/stdc++.h>
using namespace std;
int n,a[410],c[410],d[410],e[410],mn=0x3f3f3f3f;
int G(int*t,int x){int sum=0;for(int i=1;i<=n;i++)t[i]=x/a[i],x%=a[i],sum+=t[i];return sum;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		G(c,a[i]-1);
		int sum=0,mus=0;
		for(int j=i+1;j<=n;j++){
			sum+=c[j]*a[j],mus+=c[j];
			if(mus+1<G(d,sum+a[j]))mn=min(mn,sum+a[j]);
		}
	}
	printf("%d\n",mn==0x3f3f3f3f?-1:mn);
	return 0;
}