#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int main()
{
	int q;
	cin >> q;
	while(q--){
		string s, t;
		bool ok = 0;
		cin >> s >> t;
		for(auto a : s)
			for(auto b : t)
				if(a == b)
					ok = 1;
		if(ok)                    
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}