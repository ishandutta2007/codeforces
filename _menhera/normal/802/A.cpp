#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAXN = 400005;

pi a[MAXN];
int n, k, nxt[MAXN], chk[MAXN];

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a, a+n);
	memset(nxt, 0x3f, sizeof(nxt));
	for(int i=1; i<n; i++){
		if(a[i-1].first == a[i].first){
			nxt[a[i-1].second] = a[i].second;
		}
	}
	sort(a, a+n, [&](const pi &a, const pi &b){
		return a.second < b.second;
	});
	set<pi> s;
	int ans = 0;
	for(int i=0; i<n; i++){
		if(chk[a[i].first]){
			s.erase(pi(i, a[i].first));
			s.insert(pi(nxt[i], a[i].first));
			continue;
		}
		while(s.size() >= k){
			auto las = *--s.end();
			chk[las.second] = 0;
			s.erase(--s.end());
		}
		chk[a[i].first] = 1;
		s.insert(pi(nxt[i], a[i].first));
		ans++;
	}
	cout << ans;
}