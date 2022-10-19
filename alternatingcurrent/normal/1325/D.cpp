#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int qmax(int a, int b){
	return (a > b) ? a : b;
}

long long xor_sum, sum;
long long ans[66];
long long val[2][66];
long long jin[66];

long long a[100];

int main(){
	cin >> xor_sum >> sum;
	if(xor_sum > sum){
		cout << "-1" << endl;
		return 0;
	}
	for(long long i = 0; i <= 60; i++){
		val[0][i] = (xor_sum >> i) & 1;
		val[1][i] = (sum >> i) & 1; 
	}
	for(int i = 0; i <= 60; i++){
		bool need_more = val[0][i] ^ val[1][i] ^ jin[i];
		if(need_more){
			if(i == 0){
				cout << "-1" << endl;
				return 0;
			}
			ans[i-1] += 2;
			jin[i]++;
		}
		ans[i] += val[0][i];
		jin[i] += ans[i];
		jin[i+1] += (jin[i] >> 1);
	}
	int res = 0;
	for(int i = 0; i <= 60; i++) res = qmax(res, ans[i]);
	cout << res << endl;
	rep(i, 61){
		rep(j, ans[i]){
			a[j] += (1LL << i);
		}
	}
	rep(i, res) cout << a[i] << " ";
	cout << endl;
	return 0;
}