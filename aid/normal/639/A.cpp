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

int main()
{
	int n, q;
	int k;
	ios::sync_with_stdio(0);
	cin >> n >> k >> q;
	vector<int> t(n);
	set<pair<int, int> > s; 
	forn(i, n){
		cin >> t[i];
		t[i] = t[i];
	}
	int tp, id;
	forn(i, q){
		cin >> tp >> id;
		id--;
		if(tp == 1){
			s.insert(mp(t[id], id));
			while((int)s.size()>k)s.erase(s.begin());
		}
		else{
			if(s.count(mp(t[id], id)))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}