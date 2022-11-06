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
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for(int &aa : a) cin >> aa;
	bool eras[int(2e6+1)] = {};
	for(int p = 2; p < 2e6+1; ++p) if(!eras[p]) for(int j = p+p;j < 2e6+1; j += p)
		eras[j] = 1;
	int ocnt = 0;
	rep(i,0,n) ocnt += a[i]==1;
	int x=-1,y=-1,p=-1;
	rep(i,0,n) rep(j,0,i) if(!eras[a[i]+a[j]]){
		x = i, y = j;
	}
	rep(i,0,n){
		if(!eras[a[i]+1] && a[i] != 1) p = i;
	}
	if(p==-1 && y == -1){
		cout << 1 << endl;
		cout << a[0] << endl;
		return 0;
	}
	if(ocnt + (p != -1) > 2 || y == -1){
		cout << ocnt + (p != -1) << endl;
		if(p != -1) cout << a[p] << ' ';
		rep(i,0,ocnt) cout << "1 ";
		cout << endl;
	} else {
		cout << 2 << endl;
		cout << a[x] << ' ' << a[y] << endl;
	}
}