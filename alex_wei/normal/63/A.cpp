#include<bits/stdc++.h>
using namespace std;
struct node{
	string name;
	string type;
	int id;
}c[105];
int n;
int tp(string s)
{
	if(s[0]=='r')return 0;
	if(s[0]=='w'||s[1]=='h')return 1;
	if(s[0]=='m')return 2;
	if(s[0]=='c')return 3;
}
bool cmp(node a,node b){return tp(a.type)<tp(b.type)||tp(a.type)==tp(b.type)&&a.id<b.id;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i].name>>c[i].type,c[i].id=i;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
		cout<<c[i].name<<endl;
	return 0;
}