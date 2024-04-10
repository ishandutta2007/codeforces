#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int arr[200000],t;
set<int> child[200001];
queue<int> q;
bitset<200001> vis;

int main()
{jizz
	int n,a,b;
	cin >> n;
	for(int i=1;i<n;++i)
		cin >> a >> b,child[a].insert(b),child[b].insert(a);
	for(int i=0;i<n;++i)
		cin >> arr[i];
	if(arr[0]!=1)
		return cout << "No\n",0;
	q.push(1),vis[1]=1,t=1;
	while(!q.empty())
	{
		a=q.front(),q.pop();
		while(!child[a].empty())
		{
			while(!child[a].empty() && vis[*child[a].begin()]) child[a].erase(child[a].begin());
			if(child[a].empty()) break;
			if(child[a].find(arr[t])==child[a].end())
				return cout << "No\n",0;
			q.push(arr[t]),child[a].erase(arr[t]),vis[arr[t]]=1,++t;
		}
	}
	cout << "Yes\n" << "\n"; 
}