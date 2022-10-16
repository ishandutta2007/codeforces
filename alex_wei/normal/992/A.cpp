#include<bits/stdc++.h>
using namespace std;
set <int> k;
int n,a;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a)k.insert(a);
	}
	cout<<k.size();
	return 0;
}