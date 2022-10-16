#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int d,e,f; 
int main()
{
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	for(int i=0;i<a.size();i++)
		d+=a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u';
	for(int i=0;i<b.size();i++)
		e+=b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u';
	for(int i=0;i<c.size();i++)
		f+=c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u';
	if(d==5&&e==7&&f==5)cout<<"YES";
	else cout<<"NO";
	return 0;
}