//#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <string>
#include <cmath>
#include <utility>
#include <cstring>
#include <stdlib.h>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)
#define rrep(i,a,b) for(int i = int(b)-1; i >= int(a); --i)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const ll mod = 1000000007;
const int maxn = 4001;

int main(){
	int n;
	scanf("%d",&n);
	ll part[maxn][maxn] = {};
	part[0][0] = 1;
	rep(i,1,maxn)
		rep(j,1,maxn){
			part[i][j] = part[i-1][j]*j + part[i-1][j-1];
			part[i][j] %= mod;
		}
	ll bin[maxn][maxn] = {};
	bin[0][0] = 1;
	rep(i,1,maxn){
		bin[i][0] = 1;
		rep(j,1,maxn){
			bin[i][j] = bin[i-1][j] + bin[i-1][j-1];
			bin[i][j] %= mod;
		}
	}
	ll ans = 0;
	rep(i,1,n+1){
		rep(j,0,n+1)
			ans += bin[n][i]*part[n-i][j],
			ans %= mod;
	}
	printf("%d",int(ans));
}