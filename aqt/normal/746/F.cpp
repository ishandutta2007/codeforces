
// Problem : F. Music in Car
// Contest : Codeforces - Codeforces Round #386 (Div. 2)
// URL : https://codeforces.com/contest/746/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K, W;
int wt[200005];
int val[200005];
set<pair<int, int>> skip;
set<pair<int, int>> cur;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> W;
	for(int i= 1; i<=N; i++){
		cin >> val[i];
	}
	for(int i =1 ; i<=N; i++){
		cin >> wt[i];
	}
	int tot = 0, w = 0;
	int ans = 0;
	int idx = 1;
	for(int i = 1; i<=N; i++){
		if(skip.size() >= K && *skip.begin() > make_pair(wt[i], i)){
			cur.insert(make_pair(wt[i], i));
			tot += val[i];
			w += wt[i];
		}
		else{
			skip.insert(make_pair(wt[i], i));
			tot += val[i];
			w += (wt[i]+1)/2;
			if(skip.size() > K){
				auto p = *skip.begin();
				skip.erase(p);
				cur.insert(p);
				w -= (p.first+1)/2;
				w += p.first;
			}
		}
		while(w > W){
			if(cur.count(make_pair(wt[idx], idx))){
				tot -= val[idx];
				w -= wt[idx];
				cur.erase(make_pair(wt[idx], idx));
			}
			else{
				tot -= val[idx];
				w -= (wt[idx]+1)/2;
				skip.erase(make_pair(wt[idx], idx));
				if(cur.size()){
					auto p = *cur.rbegin();
					w -= p.first;
					w += (p.first+1)/2;
					skip.insert(p);
					cur.erase(p);
				}
			}
			idx++;
		}
		//cout << i << " " << tot << "\n";
		ans = max(ans, tot);
	}
	cout << ans;
}