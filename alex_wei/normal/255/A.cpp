#include<bits/stdc++.h>
using namespace std;
int n,a[3],c;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>c,a[i%3]+=c;
	if(a[0]>a[1]&&a[0]>a[2])cout<<"chest";
	else if(a[1]>a[0]&&a[1]>a[2])cout<<"biceps";
	else cout<<"back";
	return 0;
}