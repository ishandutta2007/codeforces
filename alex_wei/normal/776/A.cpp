#include<bits/stdc++.h>
using namespace std;
int n;
#define abab ababa
string a,b,c,d;
int main()
{
	cin>>a>>b>>n;
	cout<<a<<" "<<b<<endl;
	for(int i=1;i<=n;i++){
		cin>>c>>d;
		if(c==a)a=d;
		else b=d;
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}