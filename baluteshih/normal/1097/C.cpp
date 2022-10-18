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

string s;
int arr[100005],cnt[2][500005];

bool check(string s)
{
	int p=0;
	for(auto i:s)
		if(i=='(') ++p;
		else if(i==')')
			if(p==0) return 0;
			else --p;
	return 1;
}

void flip(string &s)
{
	for(int i=0;i<s.size();++i)
		if(s[i]=='(') s[i]=')';
		else s[i]='(';
}

int main()
{jizz
	int n,ans=0,tmp;
	cin >> n;
	for(int i=0;i<n;++i)
	{
		cin >> s;
		for(auto c:s)
			if(c=='(') ++arr[i];
			else --arr[i];
		if(arr[i]<0)
		{
			reverse(ALL(s));
			flip(s);
			if(check(s))	
				++cnt[1][-arr[i]];
		}
		else if(arr[i]>0)
		{
			if(check(s))
				++cnt[0][arr[i]];
		}
		else if(check(s))
		{
			reverse(ALL(s));
			flip(s);
			if(check(s))	
				++cnt[0][0];
		}
	}
	for(int i=1;i<=500000;++i)
		ans+=min(cnt[0][i],cnt[1][i]);
	cout << ans+cnt[0][0]/2 << "\n";
}