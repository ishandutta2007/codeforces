
// Problem : C. Three Bags
// Contest : Codeforces - Codeforces Round #695 (Div. 2)
// URL : https://codeforces.com/contest/1467/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int sz[3];
long long mn[3];
long long tot[3];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<long long> v;
	int A, B, C;
	cin >> A >> B >> C;
	sz[0] = A;
	sz[1] = B;
	sz[2] = C;
	/*
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	v[0] *= -1;
	v[1] *= -1;
	cout << accumulate(v.begin(), v.end(), 0);
	*/
	long long sum = 0;
	for(int k = 0; k<3; k++){
		mn[k] = LLONG_MAX/2;
		for(int i = 1; i<=sz[k]; i++){
			long long n;
			cin >> n;
			mn[k] = min(mn[k], n);
			tot[k] += n;			
		}
		sum += tot[k];
	}
	cout << sum - 2*min({tot[0], tot[1], tot[2], mn[0]+mn[1]+mn[2]-max({mn[0], mn[1], mn[2]})});
}