#include <bits/stdc++.h>

typedef long long ll;

using namespace std;



int main(){
	
	long long n, m;
	vector<long long> v;
	vector<long long> tot;
	cin >> n >> m;
	for(long long i=0; i<n; i++){
		long long x;
		cin >> x;
		v.push_back(x);
		
		tot.push_back(0);
	}
	v.push_back(1000000000);
	tot.push_back(0);
	tot.push_back(0);
	sort(v.begin(), v.end());
	for(long long i=0; i<m; i++){
		long long a, b, c;
		cin >> a >> b >> c;
		if(a!=1) continue;
		long long lo = -1;
		long long hi = v.size();
		while(hi - lo > 1){
			long long m = (hi+lo)/2;
			if(v[m] > b){
				hi = m;
			}
			else{
				lo = m;
			}
		}
		tot[hi]++;
	}
	long long mn = n+tot[v.size()];
	long long s = 0;
	
	for(long long i=v.size()-1; i>=0; i--){
		s+=tot[i+1];
		
		mn = min(i + s, mn);
	}
	cout << mn << endl;
}