
// Problem : F. Alex and a TV Show
// Contest : Codeforces - Hello 2019
// URL : https://codeforces.com/contest/1097/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
const int M = 7000;
bitset<7005> fct[7005];
bitset<7005> st[100005];
bitset<7005> mob[7005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i <= M; i++){
		for(int j = 1; j <= i; j++){
			if(i%j == 0){
				fct[i][j] = 1;
			}
		}
	}
	for(int i = 1; i <= M; i++){
		for(int j = i; j <= M; j+=i){
			mob[i][j] = 1;
		}
		for(int c = 2; c * c <= M; c++){
			for(int j = c * c * i; j <= M; j += c * c * i){
				mob[i][j] = 0;
			}
		}
	}
	while(Q--){
		int cmd, x, y, z;
		cin >> cmd;
		if(cmd == 1){
			cin >> x >> y;
			st[x] = fct[y];
		}
		else if(cmd == 2){
			cin >> x >> y >> z;
			st[x] = (st[y] ^ st[z]);
		}
		else if(cmd == 3){
			cin >> x >> y >> z;
			st[x] = (st[y] & st[z]);
		}
		else{
			cin >> x >> y;
			cout << (st[x]&mob[y]).count()%2;
		}
	}
}