#include <bits/stdc++.h>
using namespace std;
int n,a[1002],p[1000002],m,s,ap=1002;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i],p[a[i]]++,m=max(m,p[a[i]]);
	for(int i=1;i<=1000000;i++)
		if(m==p[i])
			for(int j=n-1;j>=0;j--)
				if(a[j]==i){
					if(j<ap)ap=j,s=i;
					break;
				}
	cout<<s;
    return 0;
}