
// Problem : A. Recommendations
// Contest : Codeforces Round #623 (Div. 1, based on VK Cup 2019-2020 - Elimination Round, Engine)
// URL : https://codeforces.com/contest/1314/problem/A
// Memory Limit : 512.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
int brr[200005];
map<int, vector<int>> mp;
vector<int> srt;
multiset<int> ms;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		srt.push_back(arr[i]);
	}
	for(int i = 1; i<=N; i++){
		cin >> brr[i];
		mp[arr[i]].push_back(brr[i]);
	}
	sort(srt.begin(), srt.end());
	srt.erase(unique(srt.begin(), srt.end()), srt.end());
	int idx = 0, crnt = 0;
	unsigned long long ans = 0;
	while(idx < srt.size()){
		crnt = srt[idx];
		unsigned long long tot = 0;
		do{
			if(idx < srt.size() && srt[idx] == crnt){
				idx++;
				for(auto n : mp[crnt]){
					ms.insert(n);
					tot += n;
				}	
			}
			tot -= *(--ms.end());
			ms.erase(--ms.end());
			ans += tot;
			crnt++;
		}
		while(ms.size());
	}
	cout << ans << "\n";
}