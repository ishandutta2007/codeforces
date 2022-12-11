
// Problem : E. Array Equalizer
// Contest : Codeforces - Codeforces Round #754 (Div. 2)
// URL : https://codeforces.com/contest/1605/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[200005];
long long brr[200005];
long long dif[200005];
long long ctb[200005];
long long ans[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= N; i++){
		cin >> brr[i];
		dif[i] = brr[i] - arr[i];
	}
	dif[1] = 0;
	ctb[1] = 1;
	vector<int> v;
	for(int i = 1; i <= N; i++){
		for(int j = 2 * i; j <= N; j+= i){
			dif[j] -= dif[i];
			ctb[j] -= ctb[i];
		}
		dif[i] *= -1;
		if(ctb[i]){
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end(), [](int a, int b){
		if((ctb[a] < 0) != (ctb[b] < 0)){
			return dif[a] * ctb[b] > dif[b] * ctb[a];
		}
		return dif[a] * ctb[b] < dif[b] * ctb[a];
	});
	long long tot = 0;
	long long slope = 0;
	for(int i = 1; i <= N; i++){
		tot += abs(-arr[1] * ctb[i] - dif[i]);
		slope -= abs(ctb[i]);
		//cout << ctb[i] << " " << dif[i] << "\n";
	}
	//cout << tot << endl;
	//cout << slope << endl;
	int idx = 0;
	for(long long x = -arr[1]+1; x <= -arr[1] + 1000000; x++){
		while(idx < v.size() && abs(ctb[v[idx]] * x - dif[v[idx]]) >= abs(ctb[v[idx]] * (x-1) - dif[v[idx]])){
			tot -= abs(ctb[v[idx]] * (x-1) - dif[v[idx]]);
			tot += abs(ctb[v[idx]] * x - dif[v[idx]]);
			slope += 2 * abs(ctb[v[idx]]);
			tot -= abs(ctb[v[idx]]);
			idx++;
		}
		tot += slope;
		ans[x + arr[1]] = tot;
	}
	int Q;
	cin >> Q;
	while(Q--){
		int n;
		cin >> n;
		cout << ans[n] << "\n";
	}
}