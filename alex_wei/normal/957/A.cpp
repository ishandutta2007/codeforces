#include<bits/stdc++.h>
using namespace std;
int n,ans;
vector <int> j;
string s;
void dfs(int d)
{
	if(d==j.size()){
		ans++;
		if(ans>1)cout<<"Yes",exit(0);
		return;
	}
	char r=s[j[d]];
	if(s[j[d]-1]!='C'&&s[j[d]+1]!='C')
		s[j[d]]='C',dfs(d+1),s[j[d]]=r;
	if(s[j[d]-1]!='Y'&&s[j[d]+1]!='Y')
		s[j[d]]='Y',dfs(d+1),s[j[d]]=r;
	if(s[j[d]-1]!='M'&&s[j[d]+1]!='M')
		s[j[d]]='M',dfs(d+1),s[j[d]]=r;
}
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='?')
			j.push_back(i);
		else{
			if(i>0&&s[i]==s[i-1])
				cout<<"No",exit(0);
		}
	}
	if(j.size()==0)cout<<"No",exit(0);
	if(j[0]==0||j[j.size()-1]==n-1)
		cout<<"Yes",exit(0);
	dfs(0);
	cout<<"No";
	return 0;
}