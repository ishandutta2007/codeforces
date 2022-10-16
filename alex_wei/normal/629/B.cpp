#include<bits/stdc++.h>
using namespace std;
int n,f[367],m[367],s;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		char p;
		int l,r;
		cin>>p>>l>>r;
		for(int j=l;j<=r;j++)
			p=='M'?m[j]++:f[j]++;
	}
	for(int i=1;i<367;i++)
		s=max(s,min(f[i],m[i])*2);
	cout<<s;
	return 0;
}