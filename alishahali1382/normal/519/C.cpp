#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, ans=0;
	cin>>n>>m;
	for (int i=0; i<=n; i++){
		ans=max(ans, min((n-i)/2, m-2*i) + i);
	}
	cout<<ans<<endl;
	
	return 0;
}