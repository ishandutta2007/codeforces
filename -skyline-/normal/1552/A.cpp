#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n;
char c[45],a[45];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf(" %c",c+i),a[i]=c[i];
		sort(a+1,a+n+1);
		int cnt=0;
		for(int i=1;i<=n;++i)if(a[i]!=c[i])++cnt;
		printf("%d\n",cnt);
	}
    return 0;
}