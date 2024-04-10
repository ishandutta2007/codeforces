#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

string s, ans="";
map<char, int> vis;
char arr[5][100], brr[5][100];
set<pair<char, char> > neighbours;
int dx[8]={+1, +1, +1, 0, 0, -1, -1, -1};
int dy[8]={-1, 0, +1, -1, +1, -1, 0, +1};
string str="";

void findneighbours()
{
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=13;j++)
		{
			for(int k=0;k<8;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				neighbours.insert({arr[i][j], arr[x][y]});
				neighbours.insert({arr[x][y], arr[i][j]});
			}
		}
	}
}

void makearray()
{
	int i=1, j=1, offset=1;
	for(auto it:str)
	{
		arr[i][j]=it;
		j+=offset;
		if(j==14)
		{
			i++;
			j=13;
			offset=-1;
		}
	}
}

void leftrotate(string &str, int d)
{
    reverse(str.begin(), str.begin()+d);
    reverse(str.begin()+d, str.end());
    reverse(str.begin(), str.end());
}

int32_t main()
{
	IOS;	
	int i=1, j=1, offset=1;
	cin>>s;
	for(auto it:s)
	{
		if(vis[it])
			continue;
		str+=it;
		vis[it]=1;
	}
	for(int i=0;i+1<s.size();i++)
	{
		if(s[i]==s[i+1])
		{
			cout<<"Impossible";
			return 0;
		}
	}
	while(true)
	{
		neighbours.clear();
		makearray();
		findneighbours();
		int check=1;
		for(int i=0;i+1<s.size();i++)
		{
			if(neighbours.find({s[i], s[i+1]})==neighbours.end())
			{
				check=0;
			}
		}
		leftrotate(str, 1);
		if(!check)
			continue;
		for(int i=1;i<=2;i++)
		{
			for(int j=1;j<=13;j++)
			{
				cout<<arr[i][j];
			}
			cout<<endl;
		}
		return 0;
	}
	return 0;
}