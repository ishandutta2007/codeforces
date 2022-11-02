#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int inf = 1000ll*1000ll*2000ll;
int get(int a, int b){
	if(a > b){
		int get1 = inf;
		if(a % 2 == 0) return 1+get(a/2, b);
		if(a % 3 == 0) return 1+get(a/3, b);
		if(a % 5 == 0) return 1+get(a/5, b);
		return get1;
	}
	else if(a < b){
		int get1 = inf;
		swap(a, b);
		if(a % 2 == 0) return 1+get(a/2, b);
		if(a % 3 == 0) return 1+get(a/3, b);
		if(a % 5 == 0) return 1+get(a/5, b);
		return get1;
	}
	else return 0;
}
int main () {
	int a, b, g;
	cin >> a >> b;
	g = __gcd(a, b);
	a/=g;
	b/=g;
	int x = get(a, b);
	if(x >= inf) cout << -1;
	else cout << x;
    return 0;
}