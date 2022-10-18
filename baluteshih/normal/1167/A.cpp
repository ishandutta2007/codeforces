#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main()
{jizz
	int t,n,flag=0;
	string s;
	cin >> t;
	while(t--)
	{
		cin >> n >> s,flag=0;
		for(int i=0;i<s.size();++i)
			if(s[i]=='8')
			{
				if(s.size()-i>=11) cout << "Yes\n";
				else cout << "No\n";
				flag=1;
				break;
			}
		if(!flag) cout << "No\n";		
	}
}