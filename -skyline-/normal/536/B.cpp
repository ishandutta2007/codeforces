#include<bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define mp      make_pair
#define orz     1000000007
using namespace std;
int n,z[1000005],b[1000005],s[1000005],x,y,q;
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
	scanf("%d%d",&x,&y);q=x;
	getchar();
	char c=getchar();
	while(c!='\n')a[++n]=c,c=getchar();
	getz();
	for(int i=1;i<=y;++i)scanf("%d",b+i),++s[b[i]],--s[b[i]+n];
	for(int i=2;i<=y;++i){
		int k=b[i]-b[i-1];
		if(k<n&&z[k+1]+k<n){
			puts("0");
			return 0;
		}
	}
	for(int i=1;i<=x;++i){
		s[i]+=s[i-1];
		if(s[i])--q;
	}
	ll ans=1;
	while(q--)ans=ans*26ll%1000000007ll;
	printf("%I64d\n",ans);
	return 0;
}