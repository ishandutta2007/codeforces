#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
long long mod = 1000000007;
long long binpow(long long x, long long n){
	if(!n) return 1;
	long long z = binpow(x, n/2);
	if((n&1)) return (((z *1ll*z) % mod) *1ll*x) %mod;
	return (z*1ll*z)%mod;
}
long long get(long long x, long long t){
	long long k = 0;
	while(t%x == 0){
		t/=x;
		k++;
	}
	return k;
}
long long getX(ll a, ll b){
	while(a%b == 0){
		a/=b;
	}
	return a;
}
int main () {
	long long n, c = 0, a[111111], x, ans;
	map < ll, ll > m, y;
	cin >> n >> x;
	for(int i = 0; i<n; i++){
		cin >> a[i];		
		c+=a[i];
	}
	set < ll > s;
	for(int i = 0; i<n; i++){
		a[i] = c-a[i];		
		m[a[i]]++;
		s.insert(a[i]);
	}

	while(1){
		set < long long > :: iterator it = s.begin();
		for(; it!= s.end(); it++){
			long long g = get(x, m[*it]);
			if(g==0){
				cout << binpow(x, min(c, (*it)));
				return 0;
			}
			else {
				long long k = *it;
				s.erase(it);
				s.insert( k+g);
				m[k+g] += getX(m[k], x);
				m[k] = 0;
				break;
			}
		}
	}
	cout << binpow(x, min(ans, c));
    return 0;
}