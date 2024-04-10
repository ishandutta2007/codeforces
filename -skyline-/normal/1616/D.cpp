#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,a[50005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		int m;
		scanf("%d",&m);
		for(int i=1;i<=n;++i)a[i]-=m;
		int ans=n,la=0,mn=0;
		for(int i=1;i<=n;++i){
			if(i>la+1&&mn+a[i]<0){
				la=i;
				mn=0;
				--ans;
			}
			else mn=min(mn,0)+a[i];
		}
		printf("%d\n",ans);
	}
				
    return 0;
}