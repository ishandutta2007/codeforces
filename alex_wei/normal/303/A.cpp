#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	if(n%2){
		for(int i=0;i<n;i++)cout<<i<<" ";
		cout<<endl;
		for(int i=0;i<n;i++)cout<<i<<" ";
		cout<<endl;
		for(int i=0;i<n;i++)cout<<(i+i)%n<<" ";
	}
	else cout<<-1;
	return 0;
}