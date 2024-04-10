#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, a, b, k;
char arr[N];
int pref[N];

int get(int l, int r)
{
	return pref[r] - pref[l-1];
}

int32_t main()
{
	cin>>n>>a>>b>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		pref[i]=pref[i-1] + (arr[i]=='1');
	}
	vector<int> ans;
	for(int i=b;i<=n;i++)
	{
		if(get(i-b+1, i)==0)
		{
			ans.push_back(i);
			i+=b-1;
		}
	}
	while(a>1)
	{
		ans.pop_back();
		a--;
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
		cout<<it<<" ";
}