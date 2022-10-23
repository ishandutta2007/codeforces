#include<bits/stdc++.h>
using namespace std;

int pot[500003] , N , X;

int main(){
	ios::sync_with_stdio(0); cin >> N >> X;
	for(int i = 1 ; i <= N ; ++i){int t; cin >> t; ++pot[t];}
	for(int i = 1 ; i < X ; ++i){pot[i + 1] += pot[i] / (i + 1); if(pot[i] % (i + 1) != 0){cout << "No"; return 0;}}
	cout << "Yes\n"; return 0;
}