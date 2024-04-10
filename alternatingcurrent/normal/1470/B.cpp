#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int t;
int n;
int a[300300];
int q;
long long w;
bool isprime[1010];
vector<int> prime;
map< vector<int>, int > cnt;
int ans = 0;

int main(){
	ios::sync_with_stdio(false);
	memset(isprime, 1, sizeof(isprime));
	isprime[0] = isprime[1] = 0;
	for(int i = 2; i <= 1000; i++){
		if(isprime[i]) prime.push_back(i);
		for(int j = i+i; j <= i*i && j <= 1000; j += i){
			isprime[j] = 0;
		}
	}
	cin >> t;
	while(t--){
		cin >> n;
		rep(i, n) cin >> a[i];
		cnt.clear();
		ans = 0;
		rep(i, n){
			vector<int> fori;
			rep(j, (int)prime.size()){
				if(a[i] % prime[j] == 0){
					bool cn = 0;
					while(a[i] % prime[j] == 0) cn ^= 1, a[i] /= prime[j];
					if(cn) fori.push_back(prime[j]);
				}
			}
			fori.push_back(a[i]);
			cnt[fori]++;
			ans = max(ans, cnt[fori]);
		}
		int sum = 0;
		vector<int> v;
		v.push_back(1);
		if(cnt[v] % 2 == 1) sum += cnt[v];
		for(map< vector<int>, int >::iterator it = cnt.begin(); it != cnt.end(); it++) if((it->second) % 2 == 0) sum += it->second;
		sum = max(sum, ans);
		cin >> q;
		rep(i, q){
			cin >> w;
			if(w <= 0) cout << ans << endl;
			else cout << sum << endl;
		}
	}
	return 0;
}