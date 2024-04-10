#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
	ll n, m;
	cin >> n >> m;
	ll lo = 0;
	ll hi = 1000000;
	while(hi>lo+1){
		ll md = (hi+lo)/2;
		if((md*(md+1))/2 <= n + m){
			lo = md;
		}else{
			hi = md;
		}
	}
	
	vector<int> v;
	int s = 0;
	int nx = 1;
	while(s + nx <= n){
		v.push_back(nx);
		s+=nx;
		nx++;
	}
	
	int in = v.size()-1;
	while(in >=0 && s<n){
		if((in == v.size()-1 && v[in] < lo) || (in < v.size() - 1 && v[in] < v[in+1]-1)){
			v[in]++;
			s++;
			
		}else{
			in--;
		}
	}
	
	cout << v.size() << endl;
	for(int i=0; i<v.size(); i++){
		cout << v[i];
		if(i!=v.size()-1) cout << " ";
		else cout << endl;
	}
	cout << lo - v.size() << endl;
	int i=0;
	for(int j=1; j<=lo; j++){
		while(i < v.size() && v[i] < j) i++;
		if((i < v.size() && v[i] > j )|| i==v.size()) cout << j << " ";
	}
	return 0;
}