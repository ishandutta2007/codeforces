#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long fib[60];

int main(){
	fib[0]=fib[1]=1;
	for (int i=2; i<60; i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	long long n, k;
	cin>>n>>k;
	int res[n];
	for (int i=0; i<n; i++){
		res[i]=i+1;
	}
	
	int i=1;
	k--;
	while (i<n && k>0){
		if (k>=fib[n-i]){
			k-=fib[n-i];
			swap(res[i], res[i-1]);
			i+=2;
		}
		else{
			i++;
		}
	}
	for (int i=0; i<n; i++){
		cout<<res[i]<<' ';
	}
	cout<<endl;
	
	return 0;
}