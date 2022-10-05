#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int n, k, cnt[200], mx, ans;
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;	
		cnt[x]++;
		mx = max(mx, (cnt[x] + k - 1) / k);
	}
	for(int i = 0; i < 150; i++)
		if(cnt[i])
        	ans += mx * k - cnt[i];
	cout << ans;
	return 0;
}