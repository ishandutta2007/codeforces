#include<bits/stdc++.h>
using namespace std;
string s[1005];
int mx,cnt,p;
int main()
{
	while(getline(cin,s[++cnt]))
		mx=max(mx,(int)s[cnt].size());
	for(int i=-1;i<=mx;i++)cout<<"*";
	cout<<"\n";
	for(int i=1;i<cnt;i++){
		int re=mx-s[i].size(),st=1,r=re;
		cout<<"*";
		if(re%2)p=!p,st=p;
		for(;st<=r/2;st++,re--)cout<<" ";
		cout<<s[i];
		while(re--)cout<<" ";
		cout<<"*\n";
	}
	for(int i=-1;i<=mx;i++)
		cout<<"*";
    return 0;
}