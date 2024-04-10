#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>


using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

const int C = 1000000;
int prime[C + 1]; //10^6

//f
void init_prime()
{
	fill(prime,prime + C+1,1);
	prime[0] = prime[1] = false;
	for(int i = 2; i <= C; i++) if(prime[i])
		for(int j = i * 2; j <= C; j += i) prime[j] = false;

	for(int i = 1; i <= C; i++){
		prime[i] += prime[i-1];
	}
}

int main(){
	init_prime();
	int a,b,k; cin>>a>>b>>k;
	a--;
	int cnt = prime[b] - prime[a];
	if(cnt < k){
		puts("-1");
		return 0;
	}
	int l = a+1;
	while(prime[l] - prime[a] < k) l++;
	int ans = l-a;
	while(true){
		a++;
		while(prime[l] - prime[a] < k && l <= b) l++;
		if(l > b) break;
		ans = max(ans,l-a);
	}
	int r = b-1;
	while(prime[b] - prime[r] < k) r--;
	ans = max(ans,b-r);

	cout << ans << endl;

	return 0;
}