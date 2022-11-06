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
typedef long double ld;
const ll inf = 1LL<<60;
const ld eps = 1e-14;

ll choose(ll n, ll k){
	ll res = 1;
	rep(i,0,k) res = res*(n-i)/(i+1);
	return res;
}

int main(){
	string s;
	cin >> s;
	ll a=0;
	int arr[] = {0,2,4,3,1};
	rep(i,0,5) a += int(pow(10,4-i)+eps)*(s[arr[i]]-'0');
	ll res = 1;
	rep(_,0,5) res = res*a%100000;
	printf("%05d\n",(int)res);
}