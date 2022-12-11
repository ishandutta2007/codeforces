
// Problem : B. Preparing for the Contest
// Contest : Codeforces Round #222 (Div. 1)
// URL : https://codeforces.com/contest/377/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, S;
pair<int, int> arr[100005];
pair<pair<int, int>, int> brr[100005];
int ans[100005];

bool chk(int k){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
	int idx = M;
	long long tot = 0;
	//cout << "start: " << tot << "\n";
	for(int i = N; i > 0; i-=k){
		while(idx && brr[idx].first.first >= arr[i].first){
			pq.push({brr[idx].first.second, brr[idx].second});
			//cout << " " << idx << "\n";
			idx--;
		}
		if(pq.empty()){
			return 0;
		}
		auto n = pq.top();
		pq.pop();
		//cout << tot << "\n";
		tot += n.first;
		//cout << n.first << "\n";
		//cout << "ping: " << tot << " " << n.first << "\n";
		if(tot > S){
			return 0;
		}
		for(int j = i; j>max(0, i-k); j--){
			ans[arr[j].second] = n.second;
		}
	}
	return 1;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> S;
	swap(N, M);
	for(int i =1; i<=N; i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr+1, arr+1+N);
	for(int i = 1; i<=M; i++){
		cin >> brr[i].first.first;
	}
	for(int i = 1; i<=M; i++){
		cin >> brr[i].first.second;
		brr[i].second = i;
	}
	sort(brr+1, brr+1+M);
	int l = 1, r = N, tst = -1;
	while(l <= r){
		int mid = l+r>>1;
		bool b = chk(mid);
		//cout << mid << " " << b << "\n";
		if(b){
			r = mid - 1;
			tst = mid;
		}
		else{
			l = mid + 1;
		}
	}
	if(tst == -1){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	chk(tst);
	for(int i = 1; i<=N; i++){
		cout << ans[i] << " ";
	}
}