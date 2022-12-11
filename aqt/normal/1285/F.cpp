
// Problem : F. Classical?
// Contest : Codeforces - Codeforces Round #613 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1285/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
const int M = 100000;
bool exist[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		exist[n] = 1;
	}
	long long ans = 0;
	for(int g = 1; g<=M; g++){
		vector<long long> bst;
		int G = 0;
		for(int n = M/g*g; n; n -= g){
			if(exist[n]){
				if(__gcd(G, n) != G){
					bst.push_back(n);
					G = __gcd(G, n);
				}
			}
		}
		for(long long n = g; n<=M; n+=g){
			if(exist[n]){
				for(auto k : bst){
					if(__gcd(n, k) == g){
						ans = max(ans, n * k / g);
					}
				}
			}
		}
	}
	cout << ans;
}