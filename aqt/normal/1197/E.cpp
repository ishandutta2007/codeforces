#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<long long, long long> arr[200005];
long long bitm[200005], bitc[200005];
vector<int> cmp;
const long long MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].first >> arr[i].second;
		cmp.push_back(arr[i].second);
	}
	cmp.push_back(0);
	sort(arr+1, arr+1+N);
	sort(cmp.begin(), cmp.end());
	cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
	int M = cmp.size();
	for(int idx = 1; idx<=M; idx+=(idx&-idx)){
		bitc[idx]++;
	}
	long long mxin = 0;
	long long ans = LLONG_MAX/2, anscnt = 0;
	for(int i = 1; i<=N; i++){
		mxin = max(mxin, arr[i].second);
	}
	for(int i = 1; i<=N; i++){
		int idx = lower_bound(cmp.begin(), cmp.end(), arr[i].second) - cmp.begin() + 1;
		long long bst = 0, cnt = 0;
		while(idx){
			if(bitm[idx] < bst){
				bst = bitm[idx];
				cnt = bitc[idx];
			}
			else if(bitm[idx] == bst){
				cnt += bitc[idx];
				cnt %= MOD;
			}
			idx -= idx&-idx;
		}
		if(arr[i].first > mxin){
			if(ans > bst + arr[i].second){
				ans = bst + arr[i].second;
				anscnt = cnt;
			}
			else if(ans == bst + arr[i].second){
				anscnt += cnt;
				anscnt %= MOD;
			}
		}
		else{
			bst += arr[i].second - arr[i].first;
			int idx = lower_bound(cmp.begin(), cmp.end(), arr[i].first) - cmp.begin() + 1;
			while(idx <= M){
				if(bitm[idx] > bst){
					bitm[idx] = bst;
					bitc[idx] = cnt;
				}
				else if(bitm[idx] == bst){
					bitc[idx] += cnt;
					bitc[idx] %= MOD;
				}
				idx += (idx&-idx);
			}
		}
	}
	cout << anscnt << "\n";
}