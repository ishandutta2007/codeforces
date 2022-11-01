#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define ALF 26
#define N 110
ll n,place[ALF];
string s[N];
vector <ll> v[ALF],ans;
bool mark[ALF];

void dfs(int x)
{
	mark[x]=true;
	for(int i=0;i<v[x].size();i++)
		if(mark[v[x][i]]==false)
			dfs(v[x][i]);
	place[x]=ans.size();
	ans.push_back(x);		
}


int main() {
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		if(i==0)
			continue;
		for(int j=0;j<s[i-1].size();j++)
		{
			if(s[i-1][j]!=s[i][j])
			{
				v[s[i-1][j]-'a'].push_back(s[i][j]-'a');
				break;
			}
			if(j==s[i].size()-1)
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
		}	
	}
	for(int i=0;i<ALF;i++)
		if(mark[i]==false)
			dfs(i);
	for(int i=0;i<ALF;i++)
		for(int j=0;j<v[i].size();j++)
			if(place[i]<place[v[i][j]])
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
	for(int i=ans.size()-1;i>=0;i--)
	{
		char ex=ans[i]+'a';
		cout<<ex;
	}
		
						
	return 0;
}