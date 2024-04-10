#include<bits/stdc++.h>
using namespace std;
map <string,int> k;
string a,b,c;
int g[3][3]={{0,1,0},{0,0,1},{1,0,0}};
int main()
{
	k["rock"]=0,k["scissors"]=1,k["paper"]=2;
	cin>>a>>b>>c;
	if(g[k[a]][k[b]]&&g[k[a]][k[c]])cout<<"F";
	else if(g[k[b]][k[a]]&&g[k[b]][k[c]])cout<<"M";
	else if(g[k[c]][k[a]]&&g[k[c]][k[b]])cout<<"S";
	else cout<<"?";
    return 0;
}