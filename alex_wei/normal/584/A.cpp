#include<bits/stdc++.h>
using namespace std;
int n,t;
int main()
{
	cin>>n>>t;
	if(n==1&&t==10)cout<<-1;
	else{
		cout<<t;
		for(int i=log10(t)+1;i<n;i++)cout<<0;
	}
    return 0;
}