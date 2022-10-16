#include<bits/stdc++.h>
using namespace std;
//12312
string s,t;
int a[128],b[128],p,q;
int main()
{
	cin>>s>>t;
	for(int i=0;i<s.size();i++)a[s[i]]++;
	for(int i=0;i<t.size();i++)b[t[i]]++;
	for(int i=1;i<128;i++){
		int l=min(a[i],b[i]);
		p+=l,a[i]-=l,b[i]-=l;
	}
	for(char i='a';i<='z';i++)
		q+=min(a[i],b[i-32]);
	for(char i='A';i<='Z';i++)
		q+=min(a[i],b[i+32]);
	cout<<p<<" "<<q;
	return 0;
}