#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n;
string s;
int a[100];
vector<int> g[202];
int dp[77][77][77][4];

int calc(vector<int> &a, int n, vector<int> &b, int m, vector<int> &c, int k){
	n = a.size() - n;
	m = (int) b.size() - m;
	k = (int) c.size() - k;
	int x =a[n];
	int cnt = 0;
	for(int i = m; i < b.size(); i++)
		if(b[i] < x) cnt++;
	
	for(int i = k; i < c.size(); i++)
		if(c[i] < x) cnt++;
	return cnt;
}

int get(int a, int b, int c, int ty){
	if(a + b + c == 0) return 0;
	int &res = dp[a][b][c][ty];
	if(res != -1) return res;
	res = inf;
	if(a > 0){
		if(ty != 1)  res = min(res, get(a-1, b, c, 0) + calc(g[0], a, g[1], b, g[2], c));
	}
	if(b > 0){
		res = min(res, get(a, b-1, c, 1) + calc(g[1], b, g[0], a, g[2], c));
	}
	if(c > 0){
		res = min(res, get(a, b, c-1, 2) + calc(g[2], c, g[1], b, g[0], a));
	}
	return res;
}

int main(){

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'V') a[i] = 1;
        else if (s[i] == 'K') a[i] = 0;
        else a[i] = 2;
        g[a[i]].pb(i);
    }
    memset(dp, -1, sizeof dp);
    cout << get(g[0].size(), g[1].size(), g[2].size(), 3) << endl;
    


	

    return 0;
}