
// Problem : E. The penguin's game
// Contest : Codeforces - Codeforces Round #427 (Div. 2)
// URL : https://codeforces.com/problemset/problem/835/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int tbl[2][2];

int query(vector<int> v){
	sort(v.begin(), v.end());
	if(v.empty()){
		return 0;
	}
	cout << "? " << v.size() << " ";
	for(int n : v){
		cout << n << " ";
	}
	cout << endl;
	int X;
	cin >> X;
	assert(X != -1);
	return X;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	cin >> tbl[1][0] >> tbl[1][1];
	tbl[0][1] = tbl[1][0] ^ tbl[1][1];
	int s = 0;
	for(int d = 0; d<=9; d++){
		vector<int> qu;
		for(int n = 1; n<=N; n++){
			if(n>>d&1){
				qu.push_back(n);
			}
		}
		int x = query(qu);
		if(tbl[qu.size()%2][1] == x){
			s ^= (1<<d);
		}
	}
	int b = s&(-s), i = s&(-s);
	//cout << s << endl;
	for(int d = 0; d<=9; d++){
		if(d == __builtin_ctz(b)){
			continue;
		}
		vector<int> qu;
		for(int n = 1; n<=N; n++){
			if((n&(i|(1<<d))) == (i|(1<<d))){
				qu.push_back(n);
			}
		}
		int x = query(qu);
		if(tbl[qu.size()%2][1] == x){
			//cout << "add: " << d << endl;
			i |= (1<<d);
		}
	}
	//cout << i << endl;
	int t = i;
	s ^= i;
	if(s > t){
		swap(s, t);
	}
	cout << "! " << s << " " << t << endl;
}