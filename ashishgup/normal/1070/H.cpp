#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e4+5;

int n;
string a[N];
map<string, set<int> > m;
map<string, string> m2;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=0;j<a[i].size();j++)
		{
			string cur="";
			for(int k=j;k<a[i].size();k++)
			{
				cur+=a[i][k];
				m[cur].insert(i);
				if(m2.find(cur)==m2.end())
					m2[cur]=a[i];
			}	
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		if(m.find(s)==m.end())
			cout<<"0 -"<<endl;
		else
			cout<<m[s].size()<<" "<<m2[s]<<endl;
	}
	return 0;
}