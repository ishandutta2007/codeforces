
// Problem : G. Secure Password
// Contest : Codeforces - Codeforces Round #648 (Div. 2)
// URL : https://codeforces.com/contest/1365/problem/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long val[20];
int idx[1<<14];
int mask[1005];
long long x[1005];
set<int> comp;
bool only1[65];

long long query(vector<int> v){
	if(v.empty()){
		return 0;
	}
	cout << "? " << v.size() << " ";
	for(int n : v){
		cout << n << " ";
	}
	cout << endl;
	long long n;
	cin >> n;
	return n;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vector<int> v;
	for(int m = 0; m<1<<13; m++){
		if(__builtin_popcount(m) == 6){
			v.push_back(m);
		}
	}
	for(int i= 1; i<=1000; i++){
		mask[i] = v[i-1];
		idx[v[i-1]] = i;
	}
	for(int b = 0; b<13; b++){
		vector<int> qu;
		for(int i = 1; i<=N; i++){
			if(mask[i]>>b&1){
				qu.push_back(i);
			}
		}
		val[b] = query(qu);
	}
	long long all = 0;
	for(long long b = 0; b<63; b++){
		int i = 0; 
		for(int k = 0; k<13; k++){
			if(val[k]>>b&1){
				i |= (1<<k);
			}
		}
		if(__builtin_popcount(i) == 6){
			x[idx[i]] |= (1LL<<b);
		}
		if(__builtin_popcount(i) >= 6){
			all |= (1LL<<b);
		}
	}
	cout << "! ";
	for(int i = 1; i<=N; i++){
		cout << (all^x[i]) << " ";
	}
}