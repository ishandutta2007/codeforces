#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n;
int a[100005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int x=1,y=1;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			if(a[i]>a[x])x=i;
			if(a[i]<a[y])y=i;
		}
		printf("%d %d\n",x,y);
	}
    return 0;
}