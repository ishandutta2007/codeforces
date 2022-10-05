#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

int n, d[N], ans[N];

int main(){
	n = 1000000;
	for(int i = 4; i <= n; i += 2)
		d[i] = 1;
	for(int i = 3; i <= n; i += 2){
		if(!d[i]){
			if(i > 1000)
				continue;
			for(int j = i * i; j <= n; j += i + i)
				d[j] = 1;
		}
	}

	for(int i = 2; i <= n; ++i){
		ans[i] = ans[i - 1] + (d[i] == 0);
	}

	int T;
	//cin >> T;
	scanf("%d", &T);
	while(T--){
		//cin >> n;
		scanf("%d", &n);
		//cout << ans[n] - ans[(int)sqrt(n)] + 1 << endl;
		printf("%d\n", ans[n] - ans[(int)sqrt(n)] + 1 );
	}

	return 0;
}