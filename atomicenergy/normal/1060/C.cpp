#include <bits/stdc++.h>
using namespace std;



int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> a;
	vector<long long> b;
	map<long long, long long> am;
	map<long long, long long> bm;
	for(long long i=0; i<n; i++){
		long long x;
		cin >> x;
		a.push_back(x);
	}
	for(long long i=0; i<m; i++){
		long long x;
		cin >> x;
		b.push_back(x);
	}
	long long x;
	cin >> x;
	for(long long i=0; i<n; i++){
		long long tot = 0;
		for(long long j=i; j<n; j++){
			tot+=a[j];
			if(am.count(j-i+1) == 0){
				am[j-i+1] = tot;
			}else{
				am[j-i+1] = min(am[j-i+1], tot);
			}
		}
	}
	for(long long i=0; i<m; i++){
		long long tot = 0;
		for(long long j=i; j<m; j++){
			tot+=b[j];
			if(bm.count(j-i + 1) == 0){
				bm[j-i+1] = tot;
			}else{
				bm[j-i+1] = min(bm[j-i+1], tot);
			}
		}
	}
	long long mx = 0;
	for(long long i=1; i<=n; i++){
		long long lo = 0;
		long long hi = m+1;
		while(hi-lo > 1){
			long long mi = (hi+lo)/2;
			if(am[i] * bm[mi] <= x){
				lo = mi;
			}else{
				hi = mi;
			}
		}
		mx = max(lo*i, mx);
	}
	cout << mx << endl;
	return 0;
}