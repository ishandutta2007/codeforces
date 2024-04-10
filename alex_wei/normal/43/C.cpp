#include<bits/stdc++.h>
using namespace std;
int n,a[3];
string s; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int ans=0;
		cin>>s;
		for(int j=0;j<s.size();j++)
			ans+=s[j];
		a[ans%3]++;
	}
	cout<<min(a[1],a[2])+a[0]/2;
	return 0;
}