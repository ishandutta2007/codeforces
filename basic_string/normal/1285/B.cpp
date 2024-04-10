#include<cstdio>
int a[100009];
int main(){
	int T,n,i;
	long long s,g,h;
	bool f,ff;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),f=ff=s=g=0;
		for(i=1;i<=n;++i)scanf("%d",a+i),s+=a[i];
		for(i=1;i<n;++i){
			g+=a[i];
			if(g>=s)ff=1;
			if(g<=0)g=0,f=1;
		}
		g+=a[i];
		if(g>s||(g==s&&f))ff=1;
		if(ff)puts("NO");
		else puts("YES");
	}
	return 0;
}
//$$$