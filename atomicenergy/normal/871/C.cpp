#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> uf;
vector<bool> c;

long long mm = 1000000007;

long long two(int i){
	if(i==0) return 1;
	long long z = two(i/2);
	if(i%2==0){
		return (z*z)%mm;
	}
	return (2*z*z)%mm;
}

int find(int i){
	if(uf[i] != i){
		return (uf[i] = find(uf[i]));
	}
	return i;
}

void uni(int x, int y){
	
	if(find(x) != find(y)){
		
		c[find(x)] = (c[find(x)]||c[find(y)]);
		c[find(y)] = c[find(x)];
		uf[find(x)] = uf[find(y)];
	} else{
		c[find(x)] = true;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> cs;
	map<pair<int, int>, int> ctoa;
	int ind = 0;
	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;
		if(!ctoa.count(make_pair(x, 0))){
			ctoa[make_pair(x, 0)] = ind;
			uf.push_back(ind);
			c.push_back(false);
			ind++;
			
		}
		cs.push_back(ctoa[make_pair(x, 0)]);
		if(!ctoa.count(make_pair(y, 1))){
			ctoa[make_pair(y, 1)] = ind;
			uf.push_back(ind);
			c.push_back(false);
			ind++;
		}
		cs.push_back(ctoa[make_pair(y, 1)]);
		uni(ctoa[make_pair(x, 0)], ctoa[make_pair(y, 1)]);
	}
	map<int, int> m;
	map<int, bool> b;
	for(int i=0; i<ind; i++){
		m[find(i)]++;
		b[find(i)] = c[find(i)];
	}
	long long tot = 1;
	for(pair<int, int> p : m){
		if(c[p.first]){
			tot*= two(p.second);	
		}else{
			tot *= (two(p.second)-1);
		}
		tot%=mm;
	}
	cout << tot << endl;
}