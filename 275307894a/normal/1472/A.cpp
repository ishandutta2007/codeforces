#include<cstdio>
using namespace std;
int n,m,k,x,y,z,t,ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		ans=1;
		while(n%2==0||m%2==0){
			if(n%2==0) ans*=2,n>>=1;
			else ans*=2,m>>=1;
			if(ans>=k) break; 
		}
		if(ans>=k) printf("YES\n");
		else printf("NO\n");
	}
}