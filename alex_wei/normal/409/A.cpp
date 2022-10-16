#include<bits/stdc++.h>
using namespace std;
map <char,int> k;
int c[3][3]=
{{0,1,0},
{0,0,1},
{1,0,0}},t1,t2;
string a,b;
int main()
{
	k['[']=0,k['(']=1,k['8']=2;
	cin>>a>>b;
	for(int i=0;i<a.size();i+=2)
		t1+=c[k[a[i]]][k[b[i]]],t2+=c[k[b[i]]][k[a[i]]];
	if(t1>t2)cout<<"TEAM 1 WINS";
	if(t1<t2)cout<<"TEAM 2 WINS";
	if(t1==t2)cout<<"TIE";
    return 0;
}