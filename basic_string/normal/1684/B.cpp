#include<bits/stdc++.h>
using namespace std;
enum{N=100009};
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,l;
	long long a,b,c;
	for(cin>>T;T--;){
		cin>>a>>b>>c;
		cout<<a+b+c<<' '<<
		b+c<<' '<<c<<'\n';
	}
}/*
x%y=a
y%z=b
z%x=c
z<x z=c
y%c=b 
y=b+c
x%b+c=a
x=a+b+c*/