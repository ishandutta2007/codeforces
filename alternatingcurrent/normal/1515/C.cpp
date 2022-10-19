#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int t;
int n, m, x;
priority_queue< pair<int, int> > pq;
int ans[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> m >> x;
		while(!pq.empty()) pq.pop();
		rep(i, m) pq.push(make_pair(0, i));
		rep(i, n){
			int h;
			cin >> h;
			int hh = -pq.top().first, pos = pq.top().second; pq.pop();
			ans[i] = pos;
			hh += h;
			pq.push(make_pair(-hh, pos));
		}
		cout << "YES" << endl;
		rep(i, n) cout << ans[i] + 1 << " ";
		cout << endl;
	}
	return 0;
}