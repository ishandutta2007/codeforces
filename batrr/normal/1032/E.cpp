#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 110, inf = 1e9, K = 100 * 100 + 110;
const ll INF = 1e18;

int n, ans, cnt[N], CNT;
bitset< K + 123> pre[N][N], suf[N][N], bt, tmp;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}

	pre[0][0][0] = 1;
	for(int x = 1; x <= 100; x++)
		for(int i = 0; i <= cnt[x]; i++)
        	for(int q = 0; q + i <= n; q++)
				pre[x][q + i] |= (pre[x - 1][q] << (i * x));
	
	suf[101][0][K] = 1;
	for(int x = 100; x >= 1; x--)
		for(int i = 0; i <= cnt[x]; i++)
        	for(int q = 0; q + i <= n; q++)
				suf[x][q + i] |= (suf[x + 1][q] >> (i * x));

	for(int i = 1; i <= 100; i++)
		if(cnt[i] > 0)
			CNT++;
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= cnt[i]; j++){
			int x = i * j;
			bt = 0;
			for(int q = 0; q <= j; q++){
				tmp = suf[i + 1][j - q];
				tmp >>= (K - x);
				tmp &= pre[i - 1][q];
				bt |= tmp;
			}
			if(bt == 0)
				ans = max(ans, j);
			else
				break;
			if(j == cnt[i] && CNT == 2)
				ans = n;
		}
	}
	cout << ans;
	return 0;
}