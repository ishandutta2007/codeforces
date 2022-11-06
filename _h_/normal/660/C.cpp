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
	int n,k;
	cin >> n >> k;
	vector<int> a(n), sum(n+1);
	rep(i,0,n){
		cin >> a[i];
		sum[i+1] = sum[i] + 1 - a[i];
	}
	int z = 0, l, r;
	int j = 0;
	rep(i,0,n){
		while(j < n && sum[j+1]-sum[i] <= k) j++;
		if(z < j - i){
			z = j - i;
			l = i;
			r = j;
		}
	}
	cout << z << endl;
	rep(i,l,r) a[i] = 1;
	for(int b : a) cout << b << ' ';
	cout << endl;
}