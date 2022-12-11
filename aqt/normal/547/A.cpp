// Problem : A. Mike and Frog
// Contest : Codeforces - Codeforces Round #305 (Div. 1)
// URL : https://codeforces.com/contest/547/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int M;
long long s[2], t[2];
long long c[2], b[2];
int len[2], dist[2];
int d[2];

pair<long long, long long> exteuclid(long long a, long long b){
	if(!b){
		return make_pair(a < 0 ? -1 : 1, 0);
	}
	pair<long long, long long> p = exteuclid(b, a%b);
	return make_pair(p.second, p.first - a/b * p.second);
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> M;
	for(int i = 0 ;i<2; i++){
		cin >> s[i] >> t[i] >> c[i] >> b[i];
	}
	int x = s[0], y = s[1];
	for(int i = 1; i<2*M; i++){
		x = (c[0] * x + b[0]) % M;
		y = (c[1] * y + b[1]) % M;
		if(x == t[0] && y == t[1]){
			cout << i << "\n";
			return 0;
		}
	}
	for(int i = 0; i<2; i++){
		x = y = s[i];
		do{
			x = (c[i] * x + b[i]) % M;
			y = (c[i] * y + b[i]) % M;
			y = (c[i] * y + b[i]) % M;
		} while(x != y);
		x = s[i];
		do{
			x = (c[i] * x + b[i]) % M;
			y = (c[i] * y + b[i]) % M;
		} while(x != y);
		do{
			x = (c[i] * x + b[i]) % M;
			len[i]++;
		} while(x != y);
		x = s[i];
		while(x != y){
			x = (c[i] * x + b[i]) % M;
			d[i]++;
		} 
	}	
	for(int k = 0; k < max(d[0], d[1]); k++){
		s[0] = (c[0] * s[0] + b[0]) % M;
		s[1] = (c[1] * s[1] + b[1]) % M;
	}
	for(int i = 0; i<2; i++){
		int x = s[i];
		bool vis = 0;
		do{
			if(x == t[i]){
				vis = 1;
			}			
			x = (c[i] * x + b[i]) % M;
			if(!vis){
				dist[i]++;
			}
		}
		while(x != s[i]);
		if(!vis){
			cout << -1 << "\n";
			return 0;
		}
	}
	long long G = __gcd(len[0], len[1]);
	long long L = 1LL * len[0] * len[1] / G;
	if(dist[0]%G != dist[1]%G){
		cout << -1 << "\n";
		return 0;
	} 
	//cout << len[0] << " " << len[1] << "\n";
	auto p = exteuclid(len[0], -len[1]);
	//cout << p.first << " " << p.second << "\n";
	//cout << G << "\n";
	p.first *= dist[1] - dist[0];
	p.second *= dist[1] - dist[0];
	while(p.first < 0 || p.second < 0){
		p.first += len[1] / G;
		p.second += len[0] / G;
	}
	while(p.first >= len[1] / G && p.second >= len[0] / G){
		p.first -= len[1] / G;
		p.second -= len[0] / G;
	}
	cout << p.second * len[1] + dist[1] + max(d[0], d[1]) << "\n";
}