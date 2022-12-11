
// Problem : C. Subordinates
// Contest : Codeforces - Codeforces Round #380 (Div. 1, Rated, Based on Technocup 2017 - Elimination Round 2)
// URL : https://codeforces.com/contest/737/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, S;
int arr[200005];
int srt[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	int ans = 0;
	if(arr[S]){
		arr[S] = 0;
		ans = 1;
	}
	int opt1 = -1;
	for(int i = 1; i<=N; i++){
		opt1 += !arr[i];	
	}
	set<int> st;
	for(int i = 1; i<=N; i++){
		srt[i] = arr[i];
		st.insert(arr[i]);
	}
	sort(srt+1, srt+1+N);
	int cnt = opt1, opt2 = 0;
	for(int k = 1; k<=srt[N-opt2]; k++){
		if(!st.count(k)){
			if(cnt){
				cnt--;
			}
			else{
				opt2++;
			}
		}
	}
	cout << ans+opt1+opt2 << "\n";
}