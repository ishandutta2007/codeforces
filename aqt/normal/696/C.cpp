
// Problem : C. PLEASE
// Contest : Codeforces Round #362 (Div. 1)
// URL : https://codeforces.com/contest/696/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
const long long MOD = 1e9+7;
long long base[2][2];
long long crnt[2][2];
long long temp[2][2];
long long invM[2][2];

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b,e/2);
	ret = ret*ret%MOD;
	if(e&1){
		ret = ret*b%MOD;
	}
	//cout << "expo: " << ret << "\n";
	return ret;
}

void swapmat(){
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			swap(temp[i][j], crnt[i][j]);
			temp[i][j] = 0;
		}
	}
}

void qikmatpow(long long e){
	if(!e){
		crnt[0][0] = 1;
		crnt[0][1] = 0;
		crnt[1][0] = 0;
		crnt[1][1] = 1;
		return;
	}
	qikmatpow(e/2);
	/*
	temp[0][0] = (crnt[0][0]*crnt[0][0] + crnt[0][1]*crnt[1][0])%MOD;	
	temp[0][1] = (crnt[0][0]*crnt[0][1] + crnt[0][1]*crnt[0][1])%MOD;
	temp[1][0] = (crnt[0][0]*crnt[1][1] + crnt[1][0]*crnt[1][0])%MOD;
	temp[1][1] = (crnt[1][1]*crnt[1][1] + crnt[0][1]*crnt[1][0])%MOD;
	*/
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			for(int k = 0; k<2; k++){
				temp[i][j] += (crnt[i][k]*crnt[k][j])%MOD;
			}
			temp[i][j] %= MOD;
		}
	}
	swapmat();
	if(e&1){
		/*
		for(int i = 0; i<2; i++){
			for(int j= 0; j<2;j ++){
				cout << base[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "base\n";
		*/
		for(int i = 0; i<2; i++){
			for(int j = 0; j<2; j++){
				for(int k = 0; k<2; k++){
					temp[i][j] += (crnt[i][k]*base[k][j])%MOD;
				}
				temp[i][j] %= MOD;
			}
		}
		swapmat();	
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	base[0][0] = 0;
	base[0][1] = 1;
	base[1][0] = 2;
	base[1][1] = 1;
	invM[0][0] = ((2*MOD-1) * qikpow(2, MOD-2))%MOD;
	invM[0][1] = qikpow(2, MOD-2);
	invM[1][0] = 1;
	invM[1][1] = 0;
	long long inv2M = qikpow(2, MOD-2);
	//vector<long long> v;
	long long bot = 2;
	bool all1 = 1;
	for(int i = 1; i<=N; i++){
		long long n;
		cin >> n;
		//v.push_back(n);
		qikmatpow(n);
		if(n != 1){
			all1 = 0;
		}
		swap(base[0][0], crnt[0][0]);
		swap(base[0][1], crnt[0][1]);
		swap(base[1][0], crnt[1][0]);
		swap(base[1][1], crnt[1][1]);
		/*
		for(int k= 0; k<2; k++){
			for(int j = 0; j<2;j ++){
				cout << base[k][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		*/
		bot = qikpow(bot, n);
	}
	if(all1){
		cout << "0/1\n";
		return 0;
	}
	for(int t = 0; t<2; t++){
		for(int i = 0; i<2; i++){
			for(int j = 0; j<2; j++){
				for(int k = 0; k<2; k++){
					temp[i][j] += (invM[i][k] * base[k][j]) %MOD;
				}
				temp[i][j] %= MOD;
				//cout << temp[i][j] << " ";
			}
			//cout << "\n";
		}
		for(int i = 0; i<2; i++){
			for(int j = 0; j<2; j++){
				swap(temp[i][j], base[i][j]);
				temp[i][j] = 0;
			}
		}
	}
	cout << (base[0][0] + base[0][1])%MOD << "/";
	cout << bot*inv2M%MOD << "\n"; 
}