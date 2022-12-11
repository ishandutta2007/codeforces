#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

int n;
int a[200200];
bool output;

int pref[200200];
bool up(double x) {
	int id_max = 0, id_min = 0;
	double rmax = 0, rmin = 0;
	FORI(i,n) {
		rmax = max(rmax, pref[i]-pref[id_min] - x*(i-id_min));
		rmin = min(rmin, pref[i]-pref[id_max] - x*(i-id_max));
		if (pref[i]-pref[id_max] > x * (i-id_max)) id_max = i;
		if (pref[i]-pref[id_min] < x * (i-id_min)) id_min = i;
	}
	//printf("x=%.3lf, rmin= %.3lf, rmax= %.3lf\n", x, rmin, rmax);
	if (output) printf("%.10lf\n", rmax);
	return rmax > fabs(rmin);
}

int main() {
	scanf("%d", &n);
	FORI(i,n) scanf("%d", &a[i]);
	FORI(i,n) pref[i] = pref[i-1] + a[i];
	double lo = -10101, hi = 10101;
	FOR(ii, 60) {
		double mid = (lo+hi) / 2;
		if (up(mid)) lo=mid;
		else hi=mid;
	}
	output = true;
	up((lo+hi)/2);
	return 0;
}