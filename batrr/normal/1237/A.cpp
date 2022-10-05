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
	int n, k, x;
	k = 0;
	cin >> n;
	while(n--){
		cin >> x;
		if(x & 1){
			if(k)
				x = (x + inf) / 2 - inf / 2;
			else
				x = (x + inf + 1) / 2 - inf / 2;		
			k ^= 1;
		}else
			x /= 2;
		cout << x << endl;
	}
	return 0;
}