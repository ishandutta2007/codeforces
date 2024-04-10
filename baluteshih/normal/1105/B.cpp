#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s;
int cnt[26];

int main()
{jizz
	int n,k,tmp=1;
	cin >> n >> k >> s;
	for(int i=1;i<s.size();++i)
	{
		if(tmp==k)
			++cnt[s[i-1]-'a'],tmp=1;
		else if(s[i]==s[i-1])
			++tmp;
		else
			tmp=1;
	}
	if(tmp==k)
		++cnt[s.back()-'a'];
	cout << *max_element(cnt,cnt+26) << "\n";
}