#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
using namespace std;



int main() {
	int n, r;
	cin >> n >> r;
	vector<int> f;
	vector<int> s;
	vector<int> p;
	for(int i=0; i<n; i++){
		int x, y, z;
		cin >> x >> y >> z;
		f.push_back(x);
		s.push_back(y);
		p.push_back(z);
	}
	double hi = 5000000000;
	double lo = 0;
	double mid;
	double a[51][5001];
	bool b[51][5001];
	while(hi-lo > 0.00000000001){
		mid = (hi+lo)/2;
		for(int i=n; i>=0; i--){
			for(int j=0; j<=5000; j++){
				if(i==n){
					if(j > r) {
						a[i][j] = mid;
						b[i][j] = false;
					}
					else {
						a[i][j] = 0;
						b[i][j] = true;	
					}
					continue;
				}
				if(i==0 && j==0){
					//cout << mid << " " << a[i+1][j+f[i]] << " " << a[i+1][j+s[i]] << endl;
					 //cout << p[i] * f[i] + (100-p[i]) * s[i] << endl;
				}
				if(j+s[i] > 5000) continue;
				a[i][j] = min(mid, double(p[i] * (f[i] + a[i+1][j+f[i]]) + (100-p[i]) * (s[i] + a[i+1][j+s[i]])) / 100.00);
				b[i][j] = (double(p[i] * (f[i] + a[i+1][j+f[i]]) + (100-p[i])* (s[i] + a[i+1][j+s[i]])) / 100.00) <= mid;
			}
		}
		if(b[0][0]) hi = mid;
		else lo = mid;
	}
	cout << setprecision(12) << fixed << mid << endl;
}