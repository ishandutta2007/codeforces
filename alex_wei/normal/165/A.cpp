#include<bits/stdc++.h>
using namespace std;
int n,x[202],y[202],s;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	for(int i=0;i<n;i++){
		int a=0,b=0,c=0,d=0;
		for(int j=0;j<n;j++)
			if(j!=n){
				if(x[i]<x[j]&&y[i]==y[j])
					a=1;
				if(x[i]>x[j]&&y[i]==y[j])
					b=1;
				if(y[i]>y[j]&&x[i]==x[j])
					c=1;
				if(y[i]<y[j]&&x[i]==x[j])
					d=1;
			}
		if(a&&b&&c&&d)s++;
	}
	cout<<s;
	return 0;
}