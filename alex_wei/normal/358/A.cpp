#include<bits/stdc++.h>
using namespace std;
int n,a[1002];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
			if(i!=j){
				int l=min(a[i],a[i+1]),r=max(a[i],a[i+1]),
					x=min(a[j],a[j+1]),y=max(a[j],a[j+1]);
				if(l<x&&x<r&&r<y)
					cout<<"yes",exit(0);
			}
	cout<<"no";
	return 0;
}