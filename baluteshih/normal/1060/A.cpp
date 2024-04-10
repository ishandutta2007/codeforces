#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s;

int main()
{jizz
	int n,cnt=0,ans=0;
	cin >> n >> s;
	for(char c:s)
		if(c=='8') ++cnt;
	while(n>=11&&cnt>0)
		n-=11,--cnt,ans++;
	cout << ans << "\n";
}