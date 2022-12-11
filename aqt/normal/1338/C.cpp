
// Problem : C. Perfect Triples
// Contest : Codeforces Round #633 (Div. 1)
// URL : https://codeforces.com/contest/1338/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

void rec(vector<long long> v, long long n, int lvl, int r){
	if(lvl == 0){
		//cout << r << "\n";
		cout << v[r] << "\n";
		return;
	}
	long long temp = 1LL<<(2*lvl-2);
	long long crnt = 1LL<<(2*lvl);
	for(int i = 0; i<3; i++){
		v[i] *= 4;
	}
	if(n%crnt < temp){
		
	}
	else if(n%crnt < temp*2){
		v[0]++;
		v[1]+=2;
		v[2]+=3;
	}
	else if(n%crnt < temp*3){
		v[0] += 2;
		v[1] += 3;
		v[2]++;
	}
	else{
		v[0] += 3;
		v[1]++;
		v[2] += 2;
	}
	/*
	for(int i = 0; i<3; i++){
		cout << v[i] << " ";
	}
	cout << "\n";
	*/
	rec(v, n, lvl-1, r);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	/*
	int N = 256;
	vector<int> v;
	set<int> st;
	for(int i = 1; i<=N; i++){
		if(!st.count(i)){
			//cout << i << "\n";
			for(int j = i+1; 1; j++){
				if(!st.count(j) && !st.count(j^i)){
					//cout << i << " " << j << " " << (j^i) << "\n";
					v.push_back(i);
					v.push_back(j);
					v.push_back(j^i);
					st.insert(i);
					st.insert(j);
					st.insert(j^i);
					break;
				}
			}
		}
	}
	int cnt = 0, cntr = 1;
	int nxt = 1;
	cout << cntr << ": ";
	for(int n : v){
		if(n == nxt){
			cout << "\n";
			nxt *= 4;
		}
		cout << n << " ";
		cnt++;
		if(cnt%3 == 0){
			cout << "\n";
			cout << ++cntr << ": ";
		}
	}
	*/
	int T;
	cin >> T;
	while(T--){
		long long n;
		cin >> n;
		n--;
		long long k = n%3;
		n /= 3;
		int lvl = 0;
		while(n >= (1LL<<(2*lvl))){
			n -= 1LL<<(2*lvl);
			lvl++;
		}
		//cout << n << "\n";
		rec({1, 2, 3}, n, lvl, k);
	}
}