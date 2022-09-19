// har ki ro didi goft mikhad beshe meslemon !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


int cnt[N], cnt2[N];;
int a[N];
int Main(){
	int n;
	cin >> n;
	fill(cnt, cnt + n + 1, 0);
	fill(cnt2, cnt2 + n + 1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnt2[a[i]] ++;
	}
	
	int mxx = *max_element(cnt2, cnt2 + n + 1);
	if((n+1)/2 < mxx)
		return cout << "-1\n", 0;
	int Sm = 2;
	cnt[a[1]] ++; cnt[a[n]] ++;
	int ans = 0;
	for(int i = 1; i + 1 <= n; i++){
		if(a[i] == a[i + 1]){
			cnt[a[i]] += 2;
			Sm += 2;
		} else ans ++;
	}
	// debug(ans);
	int mx = *max_element(cnt, cnt + n + 1);
	while(mx > (Sm - mx) + 2){
		Sm += 2;
		ans --;
	}
	cout << n - 1 - ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}