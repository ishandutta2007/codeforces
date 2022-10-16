#include<bits/stdc++.h>
using namespace std;
map <string,int> p;
int n,m,g[102],c[102],cnt;
string s;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>g[i];
	sort(g,g+n);
	for(int i=0;i<m;i++){
		cin>>s;
		if(!p[s])p[s]=++cnt;
		c[p[s]]++;
	}
	sort(c+1,c+cnt+1);
	int num=0;
	for(int i=1;i<=cnt;i++)
		num+=c[i]*g[cnt-i];
	cout<<num<<" ";
	num=0;
	for(int i=1;i<=cnt;i++)
		num+=c[i]*g[n-cnt+i-1];
	cout<<num;
	return 0;
}