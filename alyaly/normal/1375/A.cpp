#include<bits/stdc++.h>
using namespace std;
int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=getchar();return nans;}
int T,n,a[100001];
signed main(){
	cin>>T;
	while(T--){
		cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) if(i&1) printf("%d ",abs(a[i]));else printf("%d ",-abs(a[i]));printf("\n");
	}
	return 0;
}
/*

*/