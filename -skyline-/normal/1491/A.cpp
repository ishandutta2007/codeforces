#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,q,a[100005],c;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",a+i),c+=a[i];
	while(q--){
		int t,x;
		scanf("%d%d",&t,&x);
		if(t==1){
			c-=a[x];
			a[x]^=1;
			c+=a[x];
		}
		else{
			if(x<=c)printf("1\n");
			else printf("0\n");
		}
	}
    return 0;
}