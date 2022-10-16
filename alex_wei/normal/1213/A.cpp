#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int odd,eve,a,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a%2)odd++;
		else eve++;
	}
	cout<<min(odd,eve);
	return 0;
}