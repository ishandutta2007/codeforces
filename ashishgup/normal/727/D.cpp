#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int f[10];
bool vis[N];
string a[2][N], ans[N];
map<string, int> m;
vector<pair<pair<string, string>,int> > v;

bool comp(pair<pair<string, string>,int> &p1, pair<pair<string, string>,int> &p2)
{
	if(p1.first.first!=p2.first.first)
		return m[p1.first.first]<m[p2.first.first];
	return m[p1.first.second]<m[p2.first.second];
}

int32_t main()
{
	IOS;
	m["S"]=1;
	m["M"]=2;
	m["L"]=3;
	m["XL"]=4;
	m["XXL"]=5;
	m["XXXL"]=6;
	for(int i=1;i<=6;i++)
		cin>>f[i];	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		stringstream ss(str);
		string temp;
		int idx=0;
		while(getline(ss, temp, ','))
		{
			a[idx++][i]=temp;
		}
		if(idx==1)
		{
			f[m[a[0][i]]]--;
			ans[i]=a[0][i];
			if(f[m[a[0][i]]]<0)
			{
				cout<<"NO";
				return 0;
			}
			vis[i]=1;
		}
		else
		{
			v.push_back({{a[0][i], a[1][i]}, i});
		}
	}
	sort(v.begin(), v.end(), comp);
	for(auto it:v)
	{
		if(vis[it.second])
			continue;
		if(f[m[it.first.first]]>0)
		{
			ans[it.second]=it.first.first;
			f[m[it.first.first]]--;
		}
		else if(f[m[it.first.second]]>0)
		{
			ans[it.second]=it.first.second;
			f[m[it.first.second]]--;
		}
		else
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}