#include <bits/stdc++.h>

using namespace std;

int main(){
	int x,y,n;
	long double a,b,v;
	cin>>a>>b>>n;
	
	long double out=100000;
	for (int i=0;i<n;i++){
		cin>>x>>y>>v;
		out=min(out,hypot (x-a, y-b)/v);
	}
	cout<<setprecision(20)<<fixed<<out<<endl;
}