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
		int a[n], cnt[2];
		cnt[0] = cnt[1] = 0;
		for(int i = 0; i < n; i++){
			string s;
			cin >> s;
			a[i] = s.size();
			for(int i = 0; i < s.size(); i++)
				cnt[s[i] - '0']++;
		}	
		sort(a, a + n);
		int ans = 0;
		int x = 0, y = 0;
		for(int i = 0; i < n; i++){
			x += a[i] / 2 * 2;
			y += a[i] % 2;
			if(cnt[0] / 2 * 2 + cnt[1] / 2 * 2 >= x && cnt[0] + cnt[1] - x >= y)
				ans = i + 1;		
		}
		cout << ans << endl;
	}
	return 0;
}