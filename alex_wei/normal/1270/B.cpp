#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a[200005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int pd=0,l,r;
		for(int i=2;i<=n;i++)
			if(abs(a[i]-a[i-1])>1){
				pd=1,l=i-1,r=i;
				break;
			}
		if(pd){
			printf("YES\n%d %d\n",l,r);
		}
		else puts("NO");
	}
    return 0;
}