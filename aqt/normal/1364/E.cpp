
// Problem : E. X-OR
// Contest : Codeforces - Codeforces Round #649 (Div. 2)
// URL : https://codeforces.com/contest/1364/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int N;
int mp[3000][3000];
mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
ordered_set st;

int getint(int l, int r){
	return uniform_int_distribution<int> (l, r) (rando);
}

int query(int x, int y){
	if(x > y){
		swap(x, y);
	}
	if(mp[x][y] != -1){
		return mp[x][y];
	}
	cout << "? " << x << " " << y << "\n";
	cout.flush();
	int r;
	cin >> r;
	if(r == -1){
		exit(0);
	}
	mp[x][y] = r;
	return r;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	memset(mp, -1, sizeof mp);
	for(int i = 1; i<=N; i++){
		st.insert(i);
	}
	int idx = getint(1, N);
	st.erase(idx);
	while(1){
		//cout << idx << endl;
		int x = 2047;
		vector<int> temp;
		for(int q = 0; q<25; q++){
			if(st.size()){
				int n = getint(1, st.size());
				n--;
				int t = *st.find_by_order(n);
				x &= query(idx, t);
				temp.push_back(t);
				st.erase(st.find_by_order(n));
			}
			else{
				int n = getint(1, N);
				if(n == idx){
					continue;
				}
				x &= query(idx, n);
				temp.push_back(n);
			}
		}
		//cout << x << endl;
		//cout << " " << temp.size() << endl;
		if(!x){
			break;
		}
		assert(temp.size());
		int bst = 2047;
		for(int t : temp){
			//cout << __builtin_popcount(query(t,idx)) << " " << __builtin_popcount(bst) << endl;
			if(__builtin_popcount(query(t, idx)) < __builtin_popcount(bst)){
				bst = query(t, idx);
			}
		}
		//cout << "bst: " << bst << endl;
		int k = idx;
		for(int t : temp){
			if(bst == query(t, k)){
				st.insert(t);
				idx = t;
			}
		}
		st.erase(idx);
		//cout << "here we go again" << endl;
	}
	vector<int> ans;
	for(int n = 1; n<=N; n++){
		if(n != idx){
			ans.emplace_back(query(n, idx));
		}
		else{
			ans.emplace_back(0);
		}
	}
	cout << "! ";
	for(int n : ans){
		cout << n << " ";
	}
	cout.flush();
}