
// Problem : C. Ehab and Prefix MEXs
// Contest : Codeforces - Codeforces Round #649 (Div. 2)
// URL : https://codeforces.com/contest/1364/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[100005], brr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	set<int> st;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		st.insert(i);
	}
	for(int i = 1; i<=N; i++){
		for(int j = arr[i-1]; j<arr[i]; j++){
			brr[*(--st.upper_bound(i))] = j;
			st.erase(--st.upper_bound(i));
		}
	}
	for(int n : st){
		brr[n] = 1e6;
	}
	for(int i = 1; i<=N; i++){
		cout << brr[i] << " ";
	}
}