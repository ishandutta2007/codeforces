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
	int h1,h2,a,b;
	cin >> h1 >> h2 >> a >> b;
	int h = h2-h1-a*8;
	a*=12, b*= 12;
	int d = a-b;
	if(h <= 0){
		cout << 0 << endl;
	} else if(d <= 0){
		cout << -1 << endl;
	} else {
		cout << 1+(h-1)/d << endl;
	}
}