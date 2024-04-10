#include<bits/stdc++.h>
using namespace std;

const int _ = 2e7 + 7; bool nprm[_]; int prm[_ / 10] , cnt , num[_]; long long mx[_];

int main(){
	ios::sync_with_stdio(0);
	for(int i = 2 ; i < _ ; ++i){
		if(!nprm[i]){prm[++cnt] = i;}
		for(int j = 1;  prm[j] * i < _ ; ++j){nprm[prm[j] * i] = 1; if(i % prm[j] == 0) break;}
	}
	int N; cin >> N;
	for(int i = 1 ; i <= N ; ++i){int v; cin >> v; ++num[v];}
	for(int i = 1 ; i <= cnt ; ++i) for(int j = 2e7 / prm[i] + 1e-9 ; j >= 1 ; --j) num[j] += num[prm[i] * j];
	for(int i = 2e7 ; i ; --i){
		mx[i] = 1ll * num[i] * i;
		for(int j = 1 ; j <= cnt && prm[j] * i <= 2e7 ; ++j) mx[i] = max(mx[i] , mx[i * prm[j]] + 1ll * (num[i] - num[i * prm[j]]) * i);
	}
	cout << mx[1] << endl; return 0;
}