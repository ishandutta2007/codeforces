#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
	getline(cin,a);
	for(int i=0;i<a.size();i++)if(a[i]>='A'&&a[i]<='Z')a[i]+=32;
	for(int i=a.size()-1;i>=0;i--)
		if(a[i]>='a'&&a[i]<='z')
			cout<<(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y'?"YES":"NO"),exit(0); 
	return 0;
}