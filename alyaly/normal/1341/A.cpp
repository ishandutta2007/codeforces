#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
using namespace std;
int T,n;
int a,b,c,d;
int qread(){
	int nans=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		nans*=10;
		nans+=c-'0';
		c=getchar();
	}
	return nans;
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>a>>b>>c>>d;
		if(n*(a-b)>c+d||n*(a+b)<c-d) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
/*

*/