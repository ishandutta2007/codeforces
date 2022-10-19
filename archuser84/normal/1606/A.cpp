///
///   You fell for it, fool!
///   Thunder Cross Split Attack!
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
typedef long long ll;
using namespace std;

char s[110];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> s;
		cout << s[strlen(s)-1] << s+1 << '\n';
	}
}