#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
int T,n,m,a[100100];
double A,B,res;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),A=0,B=m,res=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1,j=n;;){
			double tim=min((a[i]-A)/i,(B-a[j])/(n-j+1));
			res+=tim;
			A+=tim*i,B-=tim*(n-j+1);
			if(abs(A-a[i])<=eps)i++;
			if(abs(B-a[j])<=eps)j--;
			if(i>j){res+=(B-A)/(i+n-j+1);break;}
		}
		printf("%.10lf\n",res);
	}
	return 0;
}