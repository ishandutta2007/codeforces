#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
int T,n,K,ffl;
int a[300001],b[300001],pb;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		pb=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1||a[i]!=a[i-1]+1){
				b[++pb]=a[i];
			}
		}
		ffl=1;
		for(int i=2;i<=pb;i++){
			if(b[i]>b[i-1]){
				ffl=0;
				break;
			}
		}
		if(ffl) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
/*

*/