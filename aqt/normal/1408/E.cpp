
// Problem : E. Avoid Rainbow Cycles
// Contest : Codeforces - Grakn Forces 2020
// URL : https://codeforces.com/contest/1408/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int dsu[200005];
int arr[200005], brr[200005];
pair<int, pair<int, int>> srt[200005];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int j = 1; j<=M; j++){
		cin >> brr[j];
	}
	iota(dsu+1, dsu+1+N+M, 1);
	long long tot = 0, mst = 0, idx = 0;
	for(int i =1 ; i<=N; i++){
		int k;
		cin >> k;
		while(k--){
			int n;
			cin >> n;
			tot += brr[n];
			tot += arr[i];
			srt[++idx] = make_pair(arr[i] + brr[n], make_pair(n, i+M));
		}
	}
	sort(srt+1, srt+1+idx);
	reverse(srt+1, srt+1+idx);
	for(int i = 1; i<=idx; i++){
		if(getrt(srt[i].second.first) != getrt(srt[i].second.second)){
			dsu[getrt(srt[i].second.first)] = getrt(srt[i].second.second);
			mst += srt[i].first;
		}
	}
	cout << tot - mst << "\n";
}