#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
ll a[200200];
map<ll, int> cnt;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		cnt.clear();
		rep(i, n){
			cin >> a[i];
			cnt[a[i]]++;
		}
		ll sum = 0;
		rep(i, n)
			sum += a[i];
		queue<ll> q;
		q.push(sum);
		bool ok = 1;
		while(!q.empty()){
			if((int)q.size() > n){
				ok = 0;
				break;
			}
			ll now = q.front();
			q.pop();
			if(cnt[now] > 0){
				cnt[now]--;
				n--;
				continue;
			}
			ll a = now / 2, b = (now + 1) / 2;
			if(cnt[a] > 0){
				cnt[a]--;
				n--;
			} else {
				q.push(a);
			}
			if(cnt[b] > 0){
				cnt[b]--;
				n--;
				continue;
			} else {
				q.push(b);
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
	return 0;
}