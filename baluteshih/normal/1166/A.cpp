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

int cnt[26];
string s;

int main()
{jizz
	int n,ans=0;
	cin >> n;
	while(n--)
	{
		cin >> s;
		cnt[s[0]-'a']++;
	}
	for(int i=0;i<26;++i)
		if(cnt[i]>=3)
			ans+=(cnt[i]/2)*(cnt[i]/2-1)/2+(cnt[i]-cnt[i]/2)*(cnt[i]-cnt[i]/2-1)/2;
	cout << ans << "\n";
}