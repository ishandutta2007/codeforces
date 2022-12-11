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

const int N = 300300;

int n,m;
string str = "ACGT";
int id[333];
string s[N], ss[N], res[N];
int best;
vi vals;
int scores[33][2];
int cnt[5][2];
int vv[33][33];

void go(bool is_rotated) {
	FOR(i,22) scores[i][0] = scores[i][1] = 0;
	FOR(i,n) {
		FOR(j,4) cnt[j][0] = cnt[j][1] = 0;
		FOR(j,m) cnt[id[s[i][j]]][j%2]++;
		FOR(j,4) FOR(k,j) {
			int val = max(cnt[j][0]+cnt[k][1], cnt[j][1]+cnt[k][0]);
			//printf("row %d (%s) -> %c %c have score %d\n", i, s[i].c_str(), str[j], str[k], val);
			scores[vv[j][k]][i%2] += val;
		}
	}
	FOR(i,4) FOR(j,i) FOR(k,4) if (k!=i&&k!=j) FOR(l,k) if (l!=i&&l!=j) {
		int cur = scores[vv[i][j]][0] + scores[vv[k][l]][1];
		//printf("rotated: %d, row0: %c %c, row1: %c %c --> score: %d+%d=%d\n", is_rotated, str[i], str[j], str[k], str[l], scores[vv[i][j]][0], scores[vv[k][l]][1], cur);
		if (cur > best) {
			best = cur;
			vals = {i,j,k,l,is_rotated};
		}
	}
}

void recon() {
	FOR(i,n) {
		FOR(j,4) cnt[j][0] = cnt[j][1] = 0;
		FOR(j,m) cnt[id[s[i][j]]][j%2]++;
		int j,k;
		if (i%2 == 0) {
			j = vals[0], k = vals[1];
		} else {
			j = vals[2], k = vals[3];
		}
		//printf("row %d (%s) -> %c %c have score %d or %d\n", i, s[i].c_str(), str[j], str[k], cnt[j][0]+cnt[k][1], cnt[j][1]+cnt[k][0]);
		res[i] = string(m, str[j]);
		if (cnt[j][0]+cnt[k][1] < cnt[j][1]+cnt[k][0]) {
			for (int q = 0; q < m; q += 2) res[i][q] = str[k];
		} else {
			for (int q = 1; q < m; q += 2) res[i][q] = str[k];
		}
		//printf("choosing %s\n", res[i].c_str());
	}
}

char tmp[N];
int main() {
	scanf("%d%d", &n, &m);
	FOR(i,n) {
		scanf("%s", tmp);
		s[i] = tmp;
	}
	id['A'] = 0;
	id['C'] = 1;
	id['G'] = 2;
	id['T'] = 3;
	int q=0;
	FOR(i,4) FOR(j,i) vv[i][j] = q++;
	go(false);
	FOR(i,n) ss[i] = s[i];
	swap(n,m);
	FOR(i,n) {
		string tt = "";
		FOR(j,m) tt += ss[j][i];
		s[i] = tt;
	}
	go(true);
	if (vals[4] == false) {
		swap(n,m);
		FOR(i,n) s[i] = ss[i];
	}
	recon();
	if (vals[4] == true) {
		FOR(i,n) ss[i] = res[i];
		swap(n,m);
		FOR(i,n) {
			string tt = "";
			FOR(j,m) tt += ss[j][i];
			res[i] = tt;
		}
		
		/*FOR(i,m) ss[i] = s[i];
		FOR(i,n) {
			string tt = "";
			FOR(j,m) tt += ss[j][i];
			s[i] = tt;
		}*/
	}
	int ret=0;
	//FOR(i,n) FOR(j,m) if (s[i][j] != res[i][j]) ret++;
	//printf("%d\n", ret);
	FOR(i,n) printf("%s\n", res[i].c_str());
	return 0;
}