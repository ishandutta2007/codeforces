#include<bits/stdc++.h>
using namespace std;

#define pii pair < int , int >
vector < int > x[100003] , y[100003]; int N , M; long long sum;

int main(){
	ios::sync_with_stdio(0); cin >> N >> M;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j){
			int c; cin >> c; x[c].push_back(i); y[c].push_back(j);
		}
	for(int i = 1 ; i <= 1e5 ; ++i){
		sort(x[i].begin() , x[i].end());
		for(int j = 0 ; j < x[i].size() ; ++j)
			sum += 1ll * x[i][j] * (-(int)(x[i].size() - 1) + j + j);
	}
	for(int i = 1 ; i <= 1e5 ; ++i){
		sort(y[i].begin() , y[i].end());
		for(int j = 0 ; j < y[i].size() ; ++j)
			sum += 1ll * y[i][j] * (-(int)(y[i].size() - 1) + j + j);
	}
	cout << sum;
	return 0;
}