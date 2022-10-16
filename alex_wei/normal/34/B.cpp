#include <bits/stdc++.h>
using namespace std;
int m,n,s,a[102]; 
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<m;i++)
		if(a[i]<0)
			s+=a[i];
	cout<<-s;
    return 0;
}