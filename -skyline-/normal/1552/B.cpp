#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,a[50005][6];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int k=1;
		for(int i=1;i<=n;++i){
			int cnt=0;
			for(int j=1;j<=5;++j){
				scanf("%d",a[i]+j);
				if(a[i][j]<a[k][j])++cnt;
			}
			if(cnt>=3)k=i;
		}
		bool ok=1;
		for(int i=1;i<=n;++i){
			if(i==k) continue;
			int cnt=0;
			for(int j=1;j<=5;++j)if(a[k][j]<a[i][j])++cnt;
			if(cnt<3)ok=0;
		}
		if(ok)printf("%d\n",k);
		else printf("-1\n");
	}
    return 0;
}