
// Problem : B. Maximal Area Quadrilateral
// Contest : Codeforces - Codeforces Round #198 (Div. 2)
// URL : https://codeforces.com/contest/340/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[305];

int crs(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	return (a.first-b.first)*(c.second-b.second) - (a.second-b.second)*(c.first-b.first);
}

long double shoelace(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	return abs(crs(a, b, c))/2.0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	long double ans = 0;
	for(int i =1 ; i<=N; i++){
		for(int j = i+1; j<=N; j++){
			long double mx1 = -1, mx2 = -1;
			for(int k = 1; k<=N; k++){
				if(k != i && k != j){
					if(crs(arr[i], arr[j], arr[k]) < 0){
						mx1 = max(mx1, shoelace(arr[i], arr[j], arr[k]));
					}
					else{
						mx2 = max(mx2, shoelace(arr[i], arr[j], arr[k]));
					}
				}
			}
			if(mx1 >= 0 && mx2 >= 0){
				ans = max(ans, mx1+mx2);
			}
		}
	}
	cout << setprecision(10) << ans << "\n";
}