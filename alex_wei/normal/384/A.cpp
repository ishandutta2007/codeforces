#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int main()
{
	cin>>n;
	cout<<(n*n+1)/2<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if((i+j)%2)cout<<'.';
			else cout<<'C';
		cout<<endl;
	}
	return 0;
}