
// Problem : A. Going Home
// Contest : Codeforces - Codeforces Round #707 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL : https://codeforces.com/contest/1500/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[200005];
pair<int, int> has[5000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr+1, arr+1+N);
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<i; j++){
			const int s = arr[i].first + arr[j].first;
			const int a = arr[i].second;
			const int b = arr[j].second;
			if(has[s].first){
				if(a != has[s].first && a != has[s].second && b != has[s].first && b != has[s].second){
					cout << "YES\n";
					cout << has[s].first << " " << has[s].second << " " << a << " " << b << "\n";
					return 0;
				}
			}
			else{
				has[s] = make_pair(a, b);
			}
		}
	}
	cout << "NO\n";
}