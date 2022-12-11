
// Problem : C. Queue in the Train
// Contest : Codeforces - Codeforces Round #594 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1239/C
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
pair<int, int> arr[100005];
int bit[100005];
long long ans[100005];

void upd(int n, int v){
	while(n <= N){
		bit[n] += v;
		n += n&-n;
	}
}

int query(int n){
	int ret = 0;
	while(n){
		ret += bit[n];
		n -= n&-n;
	}
	return ret;
}

struct mycmp {
  bool operator() (const pair<int,int> &p, const pair<int,int> &q) const {
    return p.second > q.second;
  }
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].first;
		arr[i].second = i;
		upd(i, 1);
	}
	sort(arr+1, arr+1+N);
	long long lst = 0;
	int idx = 1;
	queue<pair<int, int>> qu;
	priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> pq;
	while(idx <= N || qu.size()){
		if(qu.empty()){
			assert(pq.empty());
			lst = arr[idx].first;
			upd(arr[idx].second, -1);
			qu.push(arr[idx++]);
		}
		else{
			long long k = lst + K;
			ans[qu.front().second] = k;
			while(idx <= N && arr[idx].first < k){
				if(query(arr[idx].second) == arr[idx].second){
					qu.push(arr[idx]);
					/*
					cout << arr[idx].first << " " << arr[idx].second << " " << query(arr[idx].second) << "\n";
					for(int i = 1; i<=N; i++){
						cout << query(i) << " ";
					}
					cout << "\n";
					*/
					upd(arr[idx].second, -1);
				}
				else{
					pq.push(arr[idx]);
				}
				idx++;
			}
			upd(qu.front().second, 1);
			qu.pop();	
			while(idx <= N && arr[idx].first == k){
				pq.push(arr[idx]);
				idx++;				
			}		
			if(pq.size() && query(pq.top().second) == pq.top().second){
				qu.push(pq.top());
				upd(pq.top().second, -1);
				pq.pop();
			}
			lst = k;
		}
	}
	for(int i = 1; i<=N; i++){
		cout << ans[i] << " ";
	}
}