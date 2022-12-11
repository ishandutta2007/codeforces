
// Problem : C. Water Balance
// Contest : Codeforces - Codeforces Round #618 (Div. 1)
// URL : https://codeforces.com/contest/1299/problem/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, long long> dq[1000005];
int S = 1;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(12);
	cin >> N;
	dq[0] = {0, 0};
	long long cum = 0;
	for(int i = 1; i<=N; i++){
		long long n;
		cin >> n;
		cum += n;
		pair<int, long long> p = {i, cum};
		dq[S++] = (p);
		while(S >= 3){
			pair<int, long long> a = {dq[S-3].first-dq[S-1].first, dq[S-3].second-dq[S-1].second};
			pair<int, long long> b = {dq[S-2].first-dq[S-1].first, dq[S-2].second-dq[S-1].second};
			if(a.first * b.second - a.second * b.first <= 0){
				S--;
				dq[S-1] = p;
			}
			else{
				break;
			}
		}
	}
	int idx = 0;
	for(int i = 1; i<=N; i++){
		if(dq[idx+1].first < i){
			idx++;
		}
		//cout << dq[idx].first << " " << dq[idx+1].first << "\n";
		//cout << 1.0*(dq[idx+1].second - dq[idx].second)/(dq[idx+1].first-dq[idx].first) << "\n";		
		printf("%.10f\n", 1.0*(dq[idx+1].second - dq[idx].second)/(dq[idx+1].first-dq[idx].first));
	}
}