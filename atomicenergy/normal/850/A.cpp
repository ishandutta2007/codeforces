#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long dot(vector<long long> a, vector<long long> b){
	long long t=0;
	for(int i = 0; i<5; i++){
		t+=(a[i]*b[i]);
	}
	return t;
}

long long mag(vector<long long> a){
	long long t=0;
	for(int i=0; i<5; i++){
		t+=a[i]*a[i];	
	}
	return t;
}

vector<long long> minuss(vector<long long> a, vector<long long> b){
	vector<long long> c;
	for(int i=0; i<5; i++){
		c.push_back(b[i]-a[i]);	
	}
	return c;
}

bool acute(vector<long long> a, vector<long long> b, vector<long long> c){
	int dott = dot(minuss(b, a), minuss(c, a));
	return dott>0;
}

int main() {
	int n;
	cin >> n;
	if(n>50){
		cout << 0 << endl;
		return 0;
	}
	vector<vector<long long> > vv;
	vector<bool> ok;
	for(int i=0; i<n; i++){
		vector<long long> v;
		ok.push_back(true);
		for(int i=0; i<5; i++){
			long long x;
			cin >> x;
			v.push_back(x);
		}
		vv.push_back(v);
	}
	
	for(int i=0; i<vv.size(); i++){
	for(int j=0; j<vv.size(); j++){
	for(int k=0; k<vv.size(); k++){
		
		if(i==j || i==k || j==k){
			continue;
		}
		if(acute(vv[i], vv[j], vv[k])){
			ok[i] = false;
		}
	}	
	}	
	}
	
	int t=0;
	for(int i=0; i<vv.size(); i++){
		if(ok[i]){
			t++;	
		}
	}
	cout << t << endl;
	for(int i=0; i<vv.size(); i++){
		if(ok[i]){
			cout << i+1 << endl;	
		}
	}
	return 0;
}