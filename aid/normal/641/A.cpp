#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>
#include <map>
#include <set>
#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forab(i,a,b) for(int i=(int)a;i<(int)b;i++) //WARNING!! long long
#define mp make_pair
#define pb push_back
#define all(a,n) a,a+n
#define dprintf if(DEBUG)printf
#define dputs if(DEBUG)puts
#define dassert if(DEBUG)assert
#define fi first
#define se second
#define j0 jqwerty
#define j1 jasdf
#define i0 iqwerty
#define i1 iasdf
#define sq(x) (x)*(x)

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int DEBUG=1;
const int maxn = 200000;
string s;
int n;
int d[maxn];
int us[maxn];
void inf(){
	cout << "INFINITE\n";
	exit(0);
}
void dfs(int v){
	if(v < 0)return;
	if(v >= n)return;
	if(us[v] == 1)inf();
	if(us[v] == 2)return;
	us[v] = 1;
	if(s[v] == '<')dfs(v - d[v]);
	else dfs(v + d[v]);
	us[v] = 2;
}
int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> s;
	forn(i,n)
		cin >> d[i];
	dfs(0);
	cout << "FINITE\n";
	return 0;
}