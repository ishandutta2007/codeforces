#include <iostream>
#include <vector>
#include <map>
using namespace std;



int main() {
	long long n;
	vector<pair<int, int>> v;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	vector<int> d;
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		v.push_back(make_pair(x, i));
		a.push_back(n);
		b.push_back(-1);
		c.push_back(n);
		d.push_back(-1);
	}
	vector<pair<int, int>> z;
	 
	for(int i=0; i<n; i++){
		while(z.size()!=0 && z[z.size()-1] < v[i]){
			pair<int, int> x = z[z.size()-1];
			z.pop_back();
			a[x.second] = i;
		}
		z.push_back(v[i]);
	}
	z.clear();
	for(int i=n-1; i>=0; i--){
		while(z.size()!=0 && z[z.size()-1] < v[i]){
			pair<int, int> x = z[z.size()-1];
			z.pop_back();
			b[x.second] = i;
		}
		z.push_back(v[i]);
	}
	z.clear();
	for(int i=0; i<n; i++){
		while(z.size()!=0 && ((z[z.size()-1].first | v[i].first) != z[z.size()-1].first)){
			pair<int, int> x = z[z.size()-1];
			z.pop_back();
			c[x.second] = i;
		}
		z.push_back(v[i]);
	}
	z.clear();
	for(int i=n-1; i>=0; i--){
		while(z.size()!=0 && ((z[z.size()-1].first | v[i].first) != z[z.size()-1].first)){
			pair<int, int> x = z[z.size()-1];
			z.pop_back();
			d[x.second] = i;
		}
		z.push_back(v[i]);
	}
	long long tot = 0;
	for(int i=0; i<n; i++){
		//cout << a[i] << " --- " << c[i] << endl;
		long long mx = min(a[i], c[i]);
		long long mn = max(b[i], d[i]);
		//cout << mn << " " << mx << endl;
		long long a = mx-i;
		long long b = i-mn;
		tot += a*b;
	}
	cout << (n*(n+1))/2 - tot << endl;
}