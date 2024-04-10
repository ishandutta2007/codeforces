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
void tlen(){
		puts("IMPOSSIBLE");
	exit(0);
}
bool test(vector<int> & x);
int n, m, s, d;
vector<pair<string, int> > v; 

int mrand(){
	return rand() + (rand() << 15);
}
int main()
{
	//srand(time(0));
	ios::sync_with_stdio(0);
	cin >> n >> m >> s >> d;
	//const int e19 = 10000000;
	//const int maxn = 50;
	//n = mrand() % maxn + 1, m = mrand() % e19 + 2, s = mrand() % e19 + 1, d = mrand() % e19 + 1; 
	vector<int> x(n + 2);
	x[0] = 0;
	forn(i, n)
		//x[i + 1] = mrand() % (m - 1) + 1;
		cin >> x[i + 1];
	x[n + 1] = m;
	sort(x.begin(), x.end());

	int i = 0;
	int lst = x[i];

	while(i <  (int)x.size()){
		int nxt;
		if(i == (int)x.size() - 1)
			nxt = x[n + 1];
		else
			nxt = x[i + 1] - 1;
		if(nxt - lst < s)tlen();
		v.pb(mp("RUN", nxt - lst));
		//cerr << "R" << nxt << lst << endl;
		lst = nxt;
		if(lst == m)break;
		int j = i + 1;

		while(j < (int)x.size() - 1 && x[j + 1] - x[j] - 2 < s)j++;
	    
		if(j == (int)x.size() - 1)
			nxt = x[x.size() - 1];
		else
			nxt = x[j] + 1;
		
		if(nxt - lst > d)tlen();
		if(nxt != lst)v.pb(mp("JUMP", nxt - lst));
		//cerr << "J" << nxt << lst << endl;
		lst = nxt;
		if(lst == m)break;
		i = j;
	}
	//cerr<<"ch\n"<<n;
	
	forn(it, v.size())
		cout << v[it].first << " " << v[it].second << endl;
	
	/*if(!test(x))cerr<<"Fail\n";
	if(!test(x)){
		printf("%d %d %d %d\n", n, m, s, d);
		forn(jj, n)
			cout << x[jj] << '\n';
	}
	return !test(x);*/
	return 0;
}
bool test(vector<int> & x)
{
	set<int> pt;
	forn(i, n)
		pt.insert(x[i + 1]);
	int sum = 0;
	bool can = 0;
	forn(i, v.size()){
		if(v[i].first == "RUN"){
			can = (v[i].second >= s);
			sum += v[i].second;
		}
		else{
			if(!can){
				return false;
			}
			if(v[i].second > d) return false;
			if(pt.count(sum))return false;
			sum += v[i].second;
			if(pt.count(sum))return false;
		}
			
	}
	if(sum != m) return false;
	return true;
}