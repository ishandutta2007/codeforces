#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

int n;
map <pair <string, int>, vector <int> > M;

void add(string &a, string &b, int id){
	int Mask = 0;
	for(auto c: b)
		Mask |= 1 << (c - 'a');
	
	while(a.size()){
		int t = a[a.size() - 1] - 'a';
		if(Mask & (1 << t)){
			a.pop_back();
			continue;
		}
		
		break;
	}
	
	M[{a, Mask}].push_back(id);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		string s, t;
		cin >> s >> t;
		add(s, t, i);
	}
	
	cout << M.size() << "\n";
	for(auto v: M){
		cout << v.nd.size() << " ";
		for(int u: v.nd)
			cout << u << " ";
		cout << "\n";
	}

	return 0;
}