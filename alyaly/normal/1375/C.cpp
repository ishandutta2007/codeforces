#include<bits/stdc++.h>
using namespace std;
int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=getchar();return nans;}
int T,n,a[300001];
signed main(){
	cin>>T;
	while(T--){
		cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
		if(a[n]>a[1]) printf("YES\n");else printf("NO\n");
	}
	return 0;
}
/*

*/