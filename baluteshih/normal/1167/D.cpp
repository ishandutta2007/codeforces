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

string s;

bool check(int m)
{
	int a=0,b=0;
	for(auto c:s)
		if(c=='(')
		{
			if(a==m)
			{
				++b;
				if(b>m) return 0;
			}
			else ++a;
		}
		else
		{
			if(a==0) --b;
			else --a;
		}
	return 1;
}

int main()
{jizz
	int n,l,r,p=0;
	cin >> n >> s,l=0,r=0;
	for(auto c:s)
		if(c=='(') ++p,r=max(r,p);
		else --p;
	while(l<r)
	{
		int m=l+r>>1;
		if(check(m)) r=m;
		else l=m+1;
	}
	int a=0,b=0;
	for(auto c:s)
		if(c=='(')
		{
			if(a==l) ++b,cout << "1";
			else ++a,cout << "0";
		}
		else
		{
			if(a==0) --b,cout << "1";
			else --a,cout << "0";
		}
	ET;
}