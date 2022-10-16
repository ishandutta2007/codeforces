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

int hem(string& s, string& t){
	int a = 0;
	forn(i, s.size())
		a+=(s[i] != t[i]);
	return a;
}
int main()
{
	ios::sync_with_stdio(0);
	vector<string> v;
	int n;
	cin >> n;
	v.resize(n);
	forn(i, n)
		cin >> v[i];
	int mx = 6;
	forn(i, n){
		for(int j = i + 1; j < n; j++){
			mx = min(mx, (hem(v[i], v[j]) - 1) / 2);
		}
	}
	cout << mx << endl;
	return 0;
}