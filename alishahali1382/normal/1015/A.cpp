#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, l, r;
int res[101];

int main(){
	cin>>n>>m;
	for (int i=0; i<n; i++){
		cin>>l>>r;
		for (int j=l; j<=r; j++){
			res[j]=1;
		}
	}
	int ans=0;
	for (int i=1; i<=m; i++){
		if (!res[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	for (int i=1; i<=m; i++){
		if (!res[i]){
			cout<<i<<' ';
		}
	}
	cout<<endl;
	
	return 0;
}