#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <complex>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int pr[] = {2,3,5,7};
	int a = -1;
	string yn;
	for(int x : pr){
		cout << x << endl;
		cin >> yn;
		if(yn == "yes"){
			a = x;
		}
	}
	if(a == -1){
		cout << "prime\n";
		return 0;
	}
	vector<bool> eras(100);
	rep(p,2,100) if(!eras[p])
		for(int i = p+p; i < 100; i += p)
			eras[i] = 1;
	rep(p,2,50){
		if(eras[p]) continue;
		int pp = p * (p == a ? a : 1);
		cout << pp << endl;
		cin >> yn;
		if(yn == "yes"){
			cout << "composite\n";
			return 0;
		}
	}
	cout << "prime\n";
}