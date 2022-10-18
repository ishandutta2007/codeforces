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

string x,a[5];

int main()
{jizz
	int flag=0;
	cin >> x; 
	for(int i=0;i<5;++i)
		cin >> a[i],flag|=(a[i][0]==x[0]||a[i][1]==x[1]);
	if(flag) cout << "YES\n";
	else cout << "NO\n";
}