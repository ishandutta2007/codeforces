#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n;
int a[200005],k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1);
		a[n+1]=a[n]+k+1;
		bool ok=0;
		int o=1;
		for(int i=1;i<=n;++i){
			while(a[o]-a[i]<k)++o;
			if(a[o]-a[i]==k)ok=1;
		}	
		if(ok)puts("YES");
		else puts("NO");
	}
    return 0;
}