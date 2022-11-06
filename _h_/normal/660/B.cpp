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
typedef long double ld;

int main(){
	cin.sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	rep(i,0,n) rep(j,0,4){
		int r;
		switch(j){
			case 0:
				r = 2*n + 2*i+1;
				break;
			case 1:
				r = 2*i+1;
				break;
			case 2:
				r = 2*n + 2*i+2;
				break;
			case 3:
				r = 2*i+2;
				break;
		}
		if(r <= m)
			cout << r << ' ';
	}
	cout << endl;
}