
// Problem : F. Crossword Expert
// Contest : Codeforces - Educational Codeforces Round 68 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1194/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long T;
const long long MOD = 1e9+7;
long long fact[200005], pows[200005];

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long qikpow(long long a, long long b){
	if(!b){
		return 1;
	}
	long long ret = qikpow(a, b/2);
	ret = mult(ret, ret);
	if(b&1){
		return mult(ret, a);
	}
	return ret;
}

long long choose(long long a, long long b){
	//cout << fact[a] << " " << mult(fact[b], fact[a-b]) << "\n";
	//cout << mult(fact[a], qikpow(mult(fact[b], fact[a-b]), MOD-2)) << "\n";
	return mult(fact[a], qikpow(mult(fact[b], fact[a-b]), MOD-2));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> T;
	long long mn = 0, mx = 0;
	long long ans = 0, v = 1, k = 0;
	fact[0] = 1;
	pows[0] = 1;
	for(int i = 1; i<=N; i++){
		fact[i] = mult(fact[i-1], i);
		pows[i] = mult(pows[i-1], 2);
		int n;
		cin >> n;
		mn += n;
		mx += n+1;
		if(mn > T){
			break;
		}
		else if(mx > T){
			v = mult(v, 2);
			//cout << v << "\n";
			v = add(v, MOD-choose(i-1, k));
			//cout << v << "\n";
			mx--;
			while(mx > T){
				//cout << k << " " << choose(i, k) << "\n";
				v = add(v, MOD-choose(i, k));
				k--;
				mx--;
			}
			//cout << v << " " << mx << "\n";
			ans = add(ans, mult(v, qikpow(pows[i], MOD-2)));
		}
		else{
			k++;
			v = mult(v, 2);
			ans++;
		}
	}	
	cout << ans;
}