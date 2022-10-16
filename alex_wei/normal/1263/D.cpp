#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,d[26][26],ap[26],cnt,ca[26],tot[26],pd[26],ans;
string s[200005];
void dfs(int id)
{
	pd[id]=1;
	for(int i=0;i<26;i++)
		if(d[id][i]&&!pd[i])
			dfs(i);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		memset(ap,0,sizeof(ap));
		cnt=0;
		for(int j=0;j<s[i].size();j++)
			if(!ap[s[i][j]-'a']){
				tot[s[i][j]-'a']=1;
				ap[s[i][j]-'a']=1;
				ca[++cnt]=s[i][j]-'a';
			}
		for(int j=1;j<cnt;j++)
			for(int k=j+1;k<=cnt;k++)
				d[ca[j]][ca[k]]=d[ca[k]][ca[j]]=1;
	}
	for(int i=0;i<26;i++){
		if(tot[i]&&!pd[i]){
			ans++;
			dfs(i);
		}
	}
	cout<<ans<<endl;
    return 0;
}