#include<bits/stdc++.h>
using namespace std;
basic_string<int>a,b;
int main(){
	int T,n,i,j,k;
	double s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),s=0,a={},b={};
		for(i=1;i<=2*n;++i){
			scanf("%d%d",&j,&k);
			if(j==0)a+=abs(k);
			else b+=abs(j);
		}
		sort(a.begin(),a.end()),sort(b.begin(),b.end());
		for(i=0;i<n;++i)s+=sqrt((a[i])*1ll*(a[i])+(b[i])*1ll*(b[i]));
		printf("%.13lf\n",s);
	}
	return 0;
}