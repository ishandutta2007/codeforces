#include<bits/stdc++.h>
using namespace std;
long long t,a,b,k; 
int main()
{
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b>>k;
		cout<<(k/2)*(a-b)+(k%2)*a<<endl;
	}
	return 0;
}