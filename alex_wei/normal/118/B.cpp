#include<bits/stdc++.h>
using namespace std;
int n;
string s[10];
int main()
{
	cin>>n;
	for(int i=0;i<=n;i++){
		for(int j=0;j<(n-i)*2;j++)s[i]+=' ';
		for(int j=0;j<=i;j++){
			if(j>0)s[i]+=' ';
			s[i]+=j+'0';
		}
		for(int j=i-1;j>=0;j--)s[i]+=' ',s[i]+=j+'0';
	}
	for(int i=0;i<=n;i++)cout<<s[i]<<endl;
	for(int i=n-1;i>=0;i--)cout<<s[i]<<endl;
	return 0;
}