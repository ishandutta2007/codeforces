#include<bits/stdc++.h>
using namespace std;
int c,n,p,d;
string s; 
int main()
{
	cin>>n>>d;
	for(int i=0;i<d;i++){
		cin>>s;
		int pd=1;
		for(int j=0;j<n;j++)
			if(s[j]=='0')
				pd=0;
		if(pd)p=0;
		else p++;
		c=max(c,p);
	}
	cout<<c;
	return 0;
}