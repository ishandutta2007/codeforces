#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,s1;
map<string,string> mp;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)cin>>s>>s1,s1+=';',mp[s1]=s;
	for(int i=1;i<=m;++i)cin>>s>>s1,cout<<s<<" "<<s1<<" #"<<mp[s1]<<endl;
	return 0;
}