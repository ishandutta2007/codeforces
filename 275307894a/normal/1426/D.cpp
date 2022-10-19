#include<cstdio>
#include<map>
using namespace std;
int n,m,k,x,y,z,ans,tot,now,pus;
long long q;
map<long long ,int> s;
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);q+=x;
		if(((!q&&!s[q])||s[q])&&s[q]>=pus-1) ans++,pus=i;
		s[q]=i;
	}
	printf("%d\n",ans);
}