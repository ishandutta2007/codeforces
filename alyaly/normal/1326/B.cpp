#include<bits/stdc++.h>
using namespace std;
int n,a[300001],b[300001],ans[300001],nm;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		ans[i]=b[i]+nm;
		nm=max(nm,ans[i]);
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);printf("\n");
	return 0;
}