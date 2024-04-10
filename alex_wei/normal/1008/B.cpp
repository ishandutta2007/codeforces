#include<bits/stdc++.h>
using namespace std;
int n,p=1e9;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;
		if(l>p&&r>p)cout<<"NO",exit(0);
		if(l<=p&&r<=p)p=max(l,r);
		else if(l<=p)p=l;
		else p=r;
	}
	cout<<"YES";
	return 0;
}