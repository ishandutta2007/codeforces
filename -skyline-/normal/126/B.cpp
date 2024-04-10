#include<bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define mp      make_pair
#define orz     1000000007
using namespace std;
int n,z[1000005],b[1000005],k;
char a[1000005];
void getz(){
	int l=1,r=1;
	for(int i=2;i<=n;++i){
		if(i>r){
			l=i,r=i;
			while(r<=n&&a[r]==a[r-i+1])++r;
			z[i]=r-l,--r;
		}
		else{
			int k=i-l+1;
			if(z[k]<r-i+1)z[i]=z[k];
			else{
				l=i;
				while(r<=n&&a[r]==a[r-i+1])++r;
				z[i]=r-l,--r;
			}
		}
	}
}
int main(){
	char c=getchar();
	while(c!='\n')a[++n]=c,c=getchar();
	getz();
	for(int i=2;i<=n;++i){
		if(i+z[i]==n+1&&z[i]<=k){
			for(int j=0;j<z[i];++j)putchar(a[i+j]);
			putchar('\n');
			return 0;
		}
		k=max(k,z[i]);
	}
	puts("Just a legend");
	return 0;
}