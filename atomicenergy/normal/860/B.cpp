#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	map<string, int> m;
	for(int i=0; i<n; i++){
		string x;
		cin >> x;
		int z = stoi(x);
		v.push_back(z);
		for(int j=0; j<9; j++){
			string s = "";
			for(int k=j; k<9; k++){
				s+=x[k];
				if(!m.count(s)){
					m[s] = z;
				}else if (m[s] != z){
					m[s] = -1;	
				}
			}
		}
	}
	map<int, string> mn;
	for(auto p : m){
		if(p.second == -1) continue;
		int x = p.second;
		string z = p.first;
		if(!mn.count(x)) mn[x] = z;
		else{
			if(mn[x].size() > z.size()) mn[x] = z;
		}
	}
	for(int i=0; i<v.size(); i++){
		cout << mn[v[i]] << endl;
	}
	return 0;
}