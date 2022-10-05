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
		int n;
		cin >> n;
		map<int, int> cnt;
		while(n--){
			int x;
			cin >> x;
			cnt[x]++;
		}
		for(int i = 1; i <= 2048; i = i * 2){
			cnt[i + i] += cnt[i] / 2;
		}
		if(cnt[2048] > 0)         
			cout << "YES"<< endl;
		else
			cout << "NO"<< endl;
	}
	return 0;
}