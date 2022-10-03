#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n, m;
	cin>>n>>m;
	if (n==1){
		cout<<1<<endl;
		return 0;
	}
	if (2*m-1 == n){
		cout<<m-1<<endl;
		return 0;
	}
	if (m <= (n+1)/2){
		cout<<m+1<<endl;
		return 0;
	}
	cout<<m-1<<endl;
	return 0;
}