#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second


int main() {
	long long n;
	cin >> n;
	long long a = 0, b = 0;
	a += n;
	a += n*(n-1);
	a += n*(n-1)*(n-2)/6;
	b += n;
	b += n*(n-1)*2;
	b += n*(n-1)*(n-2);
	b += n*(n-1)*(n-2)*(n-3)/6;
	b += n*(n-1)*(n-2)*(n-3)*(n-4)/120;
	
	
	cout << a * b;
	return 0;
}