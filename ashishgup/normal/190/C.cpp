#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, sz=1;
int vis[N];
string s[N];
string ans="";

int recursion(int index)
{
	if(index>sz)
		return 0;
	if(vis[index])
		return 0;
	vis[index]=1;
	if(s[index]=="int")
	{
		ans+="int";
		return index+1;
	}
	else
	{
		ans+="pair";
		ans+="<";
		int index1=recursion(index+1);
		if(!index1)
			return 0;
		ans+=",";
		int index2=recursion(index1);
		if(!index2)
			return 0;
		ans+=">";
		return index2;
	}
}

int32_t main()
{
    IOS;
    cin>>n;
    while(cin>>s[sz])
    	sz++;
    sz--;
    int check=recursion(1);
    for(int i=1;i<=sz;i++)
    {
    	if(!vis[i])
    		check=0;
    }
    if(check)
    {
    	cout<<ans;
    }
    else
    {
    	cout<<"Error occurred";
    }
    return 0;
}