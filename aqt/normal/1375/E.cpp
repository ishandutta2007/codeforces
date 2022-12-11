#include <bits/stdc++.h>

using namespace std;

int arr[1005];
int org[1005];

struct pairofstuff{
	int l, r;
    bool operator <(const pairofstuff & temp) const{
		if(l == temp.l){
			if(org[temp.r] == org[r]){
				return r > temp.r;
			}
			return org[r] > org[temp.r];
		}
		return l < temp.l;
	}
};

int N;
vector<pairofstuff> ans[1005];
int cnt = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		org[i] = arr[i];
		for(int j = 1; j<i; j++){
			if(arr[j] > arr[i]){
				cnt++;
				ans[j].push_back({j, i});
			}
		}
	}
	for(int i = 1; i<=N; i++){
		sort(ans[i].begin(), ans[i].end());
		for(auto k : ans[i]){
			swap(arr[k.l], arr[k.r]);
		}
	}
	cout << cnt << "\n";
	for(int i = 1; i<=N; i++){
		for(auto k : ans[i]){
			cout << k.l << " " << k.r << "\n";
		}
	}
	for(int i = 2; i<=N; i++){
		assert(arr[i-1] <= arr[i]);
	}
}