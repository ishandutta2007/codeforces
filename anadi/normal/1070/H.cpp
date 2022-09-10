#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e6 + 7;

int n, q;
map <string, int> M;
map <string, string> E;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; ++i){
		string a; cin >> a;
		set <string> S;

		for(int i = 0; i < a.size(); ++i){
			string b;
			for(int j = i; j < a.size(); ++j){
				b.push_back(a[j]);
				S.insert(b);
			}
		}
		
		for(auto v: S)
			M[v]++, E[v] = a;
	}
	
	cin >> q;
	while(q--){
		string a;
		cin >> a;
		
		if(!M.count(a))
			cout << "0 -\n";
		else
			cout << M[a] << " " << E[a] << "\n";
	}

	return 0;
}