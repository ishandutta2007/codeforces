#include<bits/stdc++.h>
using namespace std;
int n,k,i;
int main()
{
	cin>>i;
	while(cin>>n>>k){
		for(i=0;i<n;i++)
			cout<<(char)(i%k+'a');
		cout<<endl;
	}
}