#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[200],b[200];
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n;i++) scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		bool flag=true;
		for(int i=0;i<n;i++){
			if(b[i]-a[i]!=0 && b[i]-a[i]!=1) flag=false;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}