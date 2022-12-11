
// Problem : D. Omkar and Medians
// Contest : Codeforces - Codeforces Round #724 (Div. 2)
// URL : https://codeforces.com/contest/1536/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		set<int> st;
		int lst = 0;
		bool good = 1;
		for(int i = 1; i <= N; i++){
			int n;
			cin >> n;
			if(i == 1){
				st.insert(n);
			}
			else{
				if(n == lst){
					
				}
				else if(n > lst){
					st.insert(n);
					if(*st.upper_bound(lst) != n){
						good = 0;
					}
				}
				else{
					st.insert(n);
					if(*(--st.lower_bound(lst)) != n){
						good = 0;
					}
				}
			}
			lst = n;
		}
		cout << (good ? "YES" : "NO") << "\n";
	}
}