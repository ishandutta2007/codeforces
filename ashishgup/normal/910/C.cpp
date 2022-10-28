#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1005;

int n;
int check[N], pw[10], contrib[10];
string s[N];

void preprocess()
{
	pw[0]=1;
	for(int i=1;i<=8;i++)
		pw[i]=pw[i-1]*10;
}

int32_t main()
{ 
	IOS;
	preprocess();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		int sz=s[i].size();
		for(int j=sz-1;j>=0;j--)
		{
			contrib[s[i][j]-'a']+=pw[sz-1-j];
		}
		check[s[i][0]-'a']=1;
	}
	vector<int> v;
	for(int i=0;i<=9;i++)
	{
		v.push_back(i);
	}
	int ans=1e9;
	do
	{
		if(check[v[0]])
			continue;
		int cur=0;
		for(int i=0;i<=9;i++)
		{
			cur+=contrib[v[i]]*i;
		}
		ans=min(ans, cur);
	}while(next_permutation(v.begin(), v.end()));
	cout<<ans;
	return 0;
}