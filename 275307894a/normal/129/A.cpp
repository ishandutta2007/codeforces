#include<bits/stdc++.h>
using namespace std;
int n,a[1001],ans,tot;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tot+=a[i];
	}
	for(int i=1;i<=n;i++) if((tot-a[i])%2==0) ans++;
	printf("%d",ans);
	return 0;
}