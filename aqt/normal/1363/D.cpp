
// Problem : D. Guess The Maximums
// Contest : Codeforces - Codeforces Round #646 (Div. 2)
// URL : https://codeforces.com/contest/1363/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int query(vector<int> v){
	cout << "? " << v.size() << " ";
	for(int n : v){
		cout << n << " ";
	}
	cout << endl;
	int n;
	cin >> n;
	assert(n != -1);
	return n;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		vector<vector<int>> v;
		for(int i = 1; i<=K; i++){
			int k;
			cin >> k;
			vector<int> t;
			for(int j = 0; j<k; j++){
				int c;
				cin >> c;
				t.push_back(c);
			}
			v.push_back(t);
		}
		vector<int> lst;
		for(int i = 1; i<=N; i++){
			lst.push_back(i);
		}
		int mx = query(lst);
		int l = 1, r = N, idx = 0;
		while(l <= r){
			int mid = (l+r)>>1;
			vector<int> qu;
			for(int k = l; k<=mid; k++){
				qu.push_back(k);
			}
			if(query(qu) == mx){
				idx = mid;
				r = mid - 1;
			}
			else{
				l = mid+1;
			}
		}
		vector<int> out(K, mx);
		//cout << "bang: " << idx << endl;
		for(int j = 0; j<K; j++){
			auto t = v[j];
			//cout << "wing: " << (find(t.begin(), t.end(), idx) != t.end()) << endl;
			if(find(t.begin(), t.end(), idx) != t.end()){
				vector<int> qu;
				for(int i = 1; i<=N; i++){
					if(find(t.begin(), t.end(), i) == t.end()){
						qu.push_back(i);
					}
				}
				//cout << "bing: " << j << endl;
				out[j] = query(qu);
			}
		}
		cout << "! ";
		for(int n : out){
			cout << n << " ";
		}
		cout << endl;
		string s;
		cin >> s;
		if(s == "Incorrect"){
			break;
		}
	}
}