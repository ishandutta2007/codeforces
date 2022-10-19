#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int solve(int x){
	int lines = 1;
	int cur  = 0;
	for(int i=0; i<v.size(); i++){
		cur += v[i];
		if(cur>x){
			cur = v[i];
			lines++;
		}
	}
	return lines;
}

int main() {
	
	
	string t;
	int n;
	char c;
	cin >> n >> c;
	getline(cin , t);
	string s = c+t;
	//cout << s << endl;
	int k = 0;
	int mn = 0;
	for(int i=0; i<s.size(); i++){
		k++;
		if(s[i] == ' ' || s[i] == '-'){
			v.push_back(k);
			mn = max(mn, k);
			//cout << k << endl;
			k=0;
		}
		
	}
	v.push_back(k);
	mn = max(mn, k);
	for(int i=0; i<v.size(); i++){
		//cout << v[i] << endl;
	}
	int lo = mn-1;
	int hi = s.size();
	while(hi-lo>1){
		int mi = (hi+lo)/2;
		if(solve(mi)<=n){
			hi = mi;
		}
		else{
			lo = mi;
		}
	}
	cout << hi << endl;
}