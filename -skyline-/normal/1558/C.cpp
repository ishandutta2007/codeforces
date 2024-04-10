#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,a[2077],b[2077];
bool _;
void prt(int x){
	if(_)printf("%d",x),_=0;
	else printf(" %d",x);
}
void f(int x){
	prt(x);
	for(int i=x/2,j=x+1-i;i;--i,++j)swap(a[i],a[j]),swap(b[a[i]],b[a[j]]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i),b[a[i]]=i;
		bool ok=1;
		for(int i=1;i<=n;++i)if((i%2)!=(a[i]%2))ok=0;
		if(!ok){
			printf("-1\n");
			continue;
		}
		printf("%d\n",(n/2)*5);
		_=1;
		for(int k=n;k>1;k-=2){
			f(b[k]);
			f(b[k-1]-1);
			f(k);
			f(b[k]);
			f(k);
		}
		printf("\n");
	}
    return 0;
}