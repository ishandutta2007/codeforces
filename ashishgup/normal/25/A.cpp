
 #include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int a[N];
vector<int> m[2];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]%2].push_back(i);
	}	
	if(m[0].size()==1)
		cout<<m[0][0];
	else
		cout<<m[1][0];
	return 0;
}