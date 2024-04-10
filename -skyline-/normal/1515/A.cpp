#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int t,n,x,a[105];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&x);
		int s=0;
		for(int i=1;i<=n;++i)scanf("%d",a+i),s+=a[i];
		if(s==x){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		s=0;
		for(int i=1;i<=n;++i){
			s+=a[i];
			if(s==x){
				swap(a[i],a[i+1]);
				break;
			}
		}
		for(int i=1;i<n;++i)printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
    return 0;
}