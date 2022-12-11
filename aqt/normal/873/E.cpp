
// Problem : E. Awards For Contestants
// Contest : Codeforces - Educational Codeforces Round 30
// URL : https://codeforces.com/contest/873/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> mx[5005][5005];
pair<int, int> arr[5005];
int org[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> org[i];
		arr[i].first = org[i];
		arr[i].second = i;
	}
	sort(arr+1, arr+1+N);
	for(int i = 1; i<N; i++){
		mx[i][i].first = arr[i+1].first - arr[i].first;
		mx[i][i].second = i+1;
	}
	for(int l = 1; l<=N; l++){
		for(int i = 1; i<=N-l-1; i++){
			mx[i][i+l] = max(mx[i+1][i+l], mx[i][i+l-1]);
		}
	}
	int typ1 = -1, typ2 = -1, typ3 = -1;
	pair<int, int> ans1, ans2, ans3;
	for(int i = 0; i<=N; i++){
		for(int j = i+1; j<N; j++){
			int x = j-i, y = N-j;
			/*
			int l = max((x+1)/2, (y+2)/3);
			int r = min(2*x, 2*y/3);
			l += j;
			r = min(r + j, N-1);
			*/
			int l = max({y-2*x, (x+1)/2, (y+2)/3});
			int r = min({y-(x+1)/2, 2*x, 2*y/3});
			l += j;
			r = min(r+j, N-1);
			//cout << i << " " << j << " " << l << " " << r << "\n";
			if(l <= r){
				if(mx[l][r].first == typ1 && arr[j+1].first-arr[j].first == typ2 && arr[i+1].first-arr[i].first > typ3){
					ans1 = arr[mx[l][r].second];
					ans2 = arr[j+1];
					ans3 = arr[i+1];
					typ3 = arr[i+1].first - arr[i].first;
				}
				else if(mx[l][r].first == typ1 && arr[j+1].first-arr[j].first > typ2){
					ans1 = arr[mx[l][r].second];
					ans2 = arr[j+1];
					ans3 = arr[i+1];
					typ3 = arr[i+1].first - arr[i].first;
					typ2 = arr[j+1].first - arr[j].first;	
				}
				else if(mx[l][r].first > typ1){
					ans1 = arr[mx[l][r].second];
					ans2 = arr[j+1];
					ans3 = arr[i+1];
					typ3 = arr[i+1].first - arr[i].first;
					typ2 = arr[j+1].first - arr[j].first;	
					typ1 = mx[l][r].first;	
				}
			}
		}
	}
	for(int i = 1; i<=N; i++){
		if(make_pair(org[i], i) >= ans1){
			cout << 1 << " ";
		}
		else if(make_pair(org[i], i) >= ans2){
			cout << 2 << " ";
		}
		else if(make_pair(org[i], i) >= ans3){
			cout << 3 << " ";
		}
		else{
			cout << -1 << " ";
		}
	}
}