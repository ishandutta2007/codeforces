#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
const ll inf = 1LL<<60;

int main(){
	int n,m;
	cin >> n >> m;
	int a=-1, b = 1e8;
	while(a+1 < b){
		int mi = (a+b)/2;
		int tva = mi/2, tre = mi/3, sni = mi/6;
		if(n <= tva && m <= tre && n+m <= tva+tre-sni){
			b = mi;
		} else
			a = mi;
	}
	cout << b << endl;
}