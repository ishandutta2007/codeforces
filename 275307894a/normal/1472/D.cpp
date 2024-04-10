#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,a[200039],t,now;
long long ans1,ans2;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);now=1;ans1=ans2=0;
		for(i=n;i;i--){
			now^=1;
			if(!(now|(a[i]&1))) ans1+=a[i];
			if(now&(a[i]&1)) ans2+=a[i];
		}
		if(ans1>ans2) printf("Alice\n");
		else if(ans1==ans2) printf("Tie\n");
		else printf("Bob\n");
	}
}