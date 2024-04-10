#include<bits/stdc++.h>
using namespace std; 
int q,a,b,c,d; 
int main()
{
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>a>>b>>c>>d;
		if(a!=c)cout<<a<<" "<<c<<endl;
		else cout<<a<<" "<<d<<endl; 
	}
	return 0;
}