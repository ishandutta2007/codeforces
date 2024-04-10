#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

struct color{
	int cmpval;
	vector<int> pos;
	bool done;
	int ind;
};
bool operator <(color a, color b){
	return a.cmpval < b.cmpval;
}
color c[111];
int n, k;
pair<int, int> ans[111];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	rep(i, n * k){
		int ci;
		cin >> ci;
		ci--;
		c[ci].pos.push_back(i);
	}
	rep(i, n)
		c[i].ind = i;
	int rem = n;
	for(int i = 1; i < k; i++){
		int now = min((n + k - 2) / (k - 1), rem);
		rem -= now;
		rep(j, n)
			c[j].cmpval = c[j].pos[i];
		sort(c, c + n);
		rep(j, n){
			if(!c[j].done){
				ans[c[j].ind] = (make_pair(c[j].pos[i - 1], c[j].pos[i]));
				c[j].done = 1;
				now--;
			}
			if(!now)
				break;
		}
	}
	rep(i, n){
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	}
	return 0;
}