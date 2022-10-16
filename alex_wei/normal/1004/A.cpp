#include <bits/stdc++.h>
using namespace std;
int n,d,a[102],s=2; 
int main()
{
	cin>>n>>d;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]>2*d)s+=2;
		if(a[i]-a[i-1]==2*d)s++;
	}
	cout<<s;
    return 0;
}