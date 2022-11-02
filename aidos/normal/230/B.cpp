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
int main () {
	set < ll > s;
	vector < bool > p(1000100, 0);
	for(int i = 2; i<2000; i++){
		if(p[i] == 0){
			for(int j=i+i; j<1000000; j+=i)
				p[j] = 1;
		}
	}
	for(int i = 2; i<1000000; i++){
		if(p[i] == 0) {
			s.insert(i*1ll*i);
		}
	}
	int n;
	cin >> n;
	for(int i = 0; i<n; i++){
		ll x;
		cin >> x;
		set < ll > :: iterator it = s.lower_bound(x);
		if(it == s.end()) cout << "NO\n";
		else if(*it != x) cout << "NO\n";
		else cout << "YES\n";
	}
    return 0;
}