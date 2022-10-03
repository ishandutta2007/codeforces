#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, ans;
int A[100000 + 10];

int f(int a, int b){
	if (a%b){
		return a/b+1;
	}
	return a/b;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//cout<<f(4, 2)<<endl;
	cin>>n;
	int mx=2*n;
	ans=-1;
	for (int i=1; i<=n; i++){
		if (mx>=i+f(n, i)){
			mx=i+f(n, i);
			ans=i;
		}
	}
	//cout<<ans<<endl;
	int cur=n;
	for (int i=0; i<n%ans; i++){
		cout<<cur-(n%ans)+i+1<<' ';
	}
	cur=cur-(n%ans);
	for (int i=0; i<n/ans; i++){
		for (int j=0; j<ans; j++){
			cout<<cur-ans+j+1<<' ';
		}
		cur-=ans;
	}
	cout<<endl;
	
	return 0;
}