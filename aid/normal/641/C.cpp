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
	ios::sync_with_stdio(0);
	//cin >> n >> q;
	scanf("%d%d", &n, &q);
	//n = 1e5, q = 2e6;
	vector<int> evn, odd;
	forn(i, n){
		if(i % 2 == 0)
			evn.pb(i);
		else
			odd.pb(i);
	}
	int x;
	int bge = 0;
	int bgo = 0;
	int tp;
	forn(i, q){
		scanf("%d", &tp);
		if(tp == 2){
			evn.swap(odd);//swap(evn, odd);
			swap(bge, bgo);
		}
		else{
			scanf("%d", &x);
			x = n - x;
			x %= n;
			if(x % 2 == 0){
				bge += x / 2;
				bgo += x / 2;
				bge %= n / 2;
				bgo %= n / 2;
				
			}
			else{
				int x2 = x / 2;
				int xx2 = x - x/2;
				bge = (bge + xx2) % int(evn.size());
				bgo = (bgo + x2) % int(odd.size());
				evn.swap(odd);///swap(evn, odd);
				swap(bge, bgo);
			}
		}
	}
	forn(i, n){
		if(i % 2 == 0){
			printf("%d ", evn[(bge + evn.size() + i / 2) % evn.size()] + 1);
		}
		else{
		    printf("%d ", odd[(bgo + evn.size() + i / 2) % evn.size()] + 1);
		}
	}
	return 0;
}