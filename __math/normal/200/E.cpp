#define _USE_MATH_DEFINES
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

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int a[3];
int ans_k3,ans_k4,ans_k5;
int ans = INT_MAX;
int n,s;

int f(int k3,int k4,int k5){
	return abs(k3*a[0]-k4*a[1]) + abs(k4*a[1]-k5*a[2]);
}

//k3,k4,k5XV
void update(int k3,int k4,int k5){
	if(ans > f(k3,k4,k5)){
		ans = f(k3,k4,k5);
		ans_k3 = k3;
		ans_k4 = k4;
		ans_k5 = k5;
	}
}

void setk3k5(int k4)
{
	//sum = s - k4*c4;
	int sum = s - k4 * a[1];

	int g = gcd(a[0],a[2]);
	// if sum % g != 0, k3,k5 are not exist. (k3c3 + k5c5 = sum)
	if(sum % g != 0) return ; 

	// a3 := k3c3,a4 := k4c4,a5 := k5c5
	int a4 = k4 * a[1];
	// f = |a4 - a3| + |a4 - a5| 
	//   = |a3 - a4| + |a3 - (s - 2 * a4)| (so, a3+a4+a5=s)
	
	// l := min(a4,s - 2 * a4), r := max(a4,s - 2 * a4)
	//if a3 range is [l,r] (l <= a3 <= r), f(k3,k4,k5) is minimum !
	//It is easy to understand that You write a graph :)

	int l = (int)ceil(min(a4,s-2*a4) / (double)a[0]);
	int r = (int)floor(max(a4,s-2*a4) / (double)a[0]);

	// swap if (l > r)
	if(l > r) swap(l,r); 

	// 0 <= k3
	// k3 <= k4 and k3*c3 + (c4+c5) * k4 <= s
	int k3_max = min(a[0]*k4,s-(a[1]+a[2])*k4)/ a[0];
	int k3_min = 0;

	//find answer in [l,r]
	for (int i = max(k3_min,l); i < r; i++){
		if(i > k3_max) break; //max is k3_max
		int a5 = (s - i*a[0] - k4*a[1]);
		if(a5 % a[2] != 0) continue;
		update(i,k4,a5 / a[2]);
		break;
	}

	//find answer in (-,l]
	for (int i = min(k3_max,l); i >= k3_min; i--){
		int a5 = (s - i*a[0] - k4*a[1]);
		if(a5 % a[2] != 0) continue;
		update(i,k4,a5 / a[2]);
		break;
	}

	//find answer in [r,)
	for (int i = max(k3_min,r); i <= k3_max; i++){
		int a5 = (s - i*a[0] - k4*a[1]);
		if(a5 % a[2] != 0) continue; 
		update(i,k4,a5 / a[2]);
		break;
	}
}

int main()
{
	cin>>n>>s;
	for (int i = 0; i < n; i++){
		int x; cin>>x; a[x-3]++;
	}

	// k4 <= k5 --->  k4*c4 + k4*c5 <= s
	for (int i = 0; (i * (a[1] + a[2])) <= s; i++){
		setk3k5(i); // i = k4
	}
	if(ans == INT_MAX){
		puts("-1");
	} else {
		printf("%d %d %d\n",ans_k3,ans_k4,ans_k5);
	}

	return 0;
}