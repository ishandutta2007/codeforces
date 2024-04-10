#include<bits/stdc++.h>
using namespace std;
int n,a[10],b[10],c[10],d[10],pd=1;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<2*n;i++)i<n?a[s[i]-'0']++:b[s[i]-'0']++;
	for(int i=0;i<10;i++)c[i]=a[i],d[i]=b[i];
	for(int i=0;i<10;i++)
		if(a[i])
			for(int j=0;j<10;j++)
				if(b[j]&&j<=i)
					pd=min(pd,0);
				else{int r=min(a[i],b[j]);a[i]-=r,b[j]-=r;}
	if(pd)cout<<"YES",exit(0);
	pd=1;
	for(int i=9;i>=0;i--)
		if(c[i])
			for(int j=9;j>=0;j--)
				if(d[j]&&j>=i)pd=min(pd,0);
				else{int r=min(c[i],d[j]);c[i]-=r,d[j]-=r;}
	if(pd)cout<<"YES";
	else cout<<"NO";
	return 0;
}