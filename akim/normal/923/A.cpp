//Solution by Tima
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = int(1e6) + 10, mod = int(1e9)  + 7; 

int n;

int lp[N];

int get(int n){
	if(n == lp[n]) return mod;
	return n - lp[n] + 1;
}
int main () {
	cin >> n;
	for(int i = 2; i <= n; i++) if(!lp[i]){
		for(int j = i; j <= n; j += i){
			lp[j] = i;
		}
	}
	int ans = mod;
	for(int i = n - lp[n] + 1; i <= n; i++){
		ans = min(ans, get(i));
	}
	cout << ans;

return 0;
}