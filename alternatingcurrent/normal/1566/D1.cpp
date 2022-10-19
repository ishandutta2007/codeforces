#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, m;
pair<int, int> a[100100];
int ind[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, n * m)
			cin >> a[i].first, a[i].second = i;
		sort(a, a + n * m);
		int i = 0;
		int nowpos = 0;
		while(i < n * m){
			int j = i;
			while(j < n * m && a[j].first == a[i].first)
				j++;
			while(i < j){
				int lastpos = nowpos;
				while(i < j){
					ind[nowpos] = a[i].second;
					nowpos++;
					i++;
					if(nowpos % m == 0)
						break;
				}
				reverse(ind + lastpos, ind + nowpos);
			}
		}
		int ans = 0;
		rep(i, n)
			rep(j, m)
				rep(k, j)
					ans += ind[i * m + k] < ind[i * m + j];
		cout << ans << endl;
	}
	return 0;
}