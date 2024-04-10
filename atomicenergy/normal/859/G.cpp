#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;




int main() {
	
	int n;
	vector<int> p;
	vector<int> o;
	cin >> n;
	int k = n;
	int z = 2;
	int y = 1;

	while(k!=1){
	
		if(k%z != 0){
			z++;
			continue;
		}
		int q = z;
		while(k%q == 0){
			q*=z;
		}
		q/=z;
		k/=q;
		y *= z;
		p.push_back(z);
		o.push_back(z); 
		z++;
	}
	y = n/y;
	int a[100000];

	map<pair<int, vector<int>>, int> m;
	vector<int> e;
	for(int i=1; i<n+1; i++){
		char c;
		cin >> c;
		
		vector<int> v;
		for(int j=0; j<p.size(); j++){
			v.push_back((i/y)%(p[j]));
		}
		e.push_back( (c - '0'));
		m[make_pair(i%y,v)] = (c - '0');
	}
	vector<int> v;
	for(int j=0; j<p.size(); j++){
		v.push_back(0);
	}
	bool okie = true;
	
	while(true){
		int z = 0;
		while(z < p.size() && v[z] == p[z]-1) {
			v[z] = 0;
			z++;
		}
		if(z == p.size()) break;
		v[z]++;
		bool ok = false;
		
		for(int j=0; j<p.size(); j++){
			if(!v[j]) ok = true;
		}
		if(ok) continue;
		
		
		for(int j=0; j<y; j++){
			int tot = 0;
		for(int i=0; i<(1<<p.size()); i++){
			vector<int> k;
			int rt = 1;
			for(int w = 0; w<p.size(); w++){
				if(i & (1<<w)){
					rt *= -1;
					k.push_back(v[w]);
				}else{
					k.push_back(0);
				}
			}
			tot += (rt * m[make_pair(j, k)]);
			
		}

		if(tot) okie = false;
		}
	}
	
	if(okie) cout << "YES" << endl;
	else{
		cout << "NO" << endl;
	}
	return 0;
	 
}