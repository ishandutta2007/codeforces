#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,id[N]; 
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>id[i];
		if(k>i)k-=i;
		else cout<<id[k]<<endl,exit(0);
	}
	return 0;
}