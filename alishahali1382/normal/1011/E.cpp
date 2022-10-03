#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k, tmp, x;

int gcd(int a, int b){
	if (!b) return a;
	return gcd(b, a%b);
}

int main(){
	cin>>n>>k;
	x=k;
	for (int i=0; i<n; i++){
		cin>>tmp;
		x=gcd(x, tmp%k);
	}
	if (x==0){
		cout<<1<<endl<<0<<endl;
		return 0;
	}
	cout<<k/x<<endl;
	for (int i=0; i<k; i+=x){
		cout<<i<<' ';
	}
	cout<<endl;
	
	return 0;
}