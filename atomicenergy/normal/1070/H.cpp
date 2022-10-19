#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	map<string, int> x;
	map<string, string> y; 
	for(int k=0; k<n; k++){
		string s;
		cin >> s;
		set<string> ss;
		for(int i=0; i<s.size(); i++){
			string t = "";
			for(int j = i; j<s.size(); j++){
				t+=s[j];
				y[t] = s;
				ss.insert(t);
			}
			
		}
		for(string t : ss){
			x[t]++;
		}
	}
	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		string s;
		cin >> s;
		if(!y.count(s))y[s] = "-";
		cout << x[s] << " " << y[s] << endl;
	}
}