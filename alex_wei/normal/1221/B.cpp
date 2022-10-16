#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if((i+j)%2)cout<<"W";
			else cout<<"B";
		cout<<endl;
	}
    return 0;
}