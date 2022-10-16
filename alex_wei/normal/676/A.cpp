#include<bits/stdc++.h>
using namespace std;
int n,a[105],pi,px; 
int main()
{
	cin>>n;
	pi=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[pi])pi=i;
		if(a[i]>a[px])px=i;
	}
	if(pi>px)swap(pi,px);
	cout<<max(px-1,n-pi);
	return 0;
}