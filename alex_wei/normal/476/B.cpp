#include<bits/stdc++.h>
using namespace std;
string s,t;
int pos;
double ans;
void dfs(int id,int p,double posi)
{
	if(id==t.size()){if(pos==p)ans+=posi;return;}
	if(t[id]=='-')dfs(id+1,p-1,posi);
	else if(t[id]=='+')dfs(id+1,p+1,posi);
	else dfs(id+1,p+1,posi/2),dfs(id+1,p-1,posi/2);
}
int main()
{
	cin>>s>>t;
	for(int i=0;i<s.size();i++)
		s[i]=='-'?pos--:pos++;
	dfs(0,0,1.0);
	printf("%.9lf",ans); 
	return 0;
}