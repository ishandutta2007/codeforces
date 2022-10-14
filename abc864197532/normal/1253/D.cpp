#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>
int dij[200000],minn[200000], maxx[200000];

int find (int n) {
    if (dij[n] == n) return n;
    return dij[n] = find(dij[n]);
}

bool unions (int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return false;
    if (x > y) swap(x,y);
    dij[x] = y;
    minn[x] = min(minn[x], minn[y]);
    maxx[x] = max(maxx[x], maxx[y]);
    return true;
}


int main () {
	int n,m;
	cin >> n >> m;
	fop (i,0,n) {
	    dij[i] = i;
	    minn[i] = i;
	    maxx[i] = i;
	} fop (i,0,m) {
	    int a,b;
	    cin >> a >> b;
	    a--;
	    b--;
	    unions(a,b);
	}
	int ans = 0;
	bool vi[n];
	fop (i,0,n) vi[i] = false;
	fop (i,0,n) {
	    if (vi[i]) continue;
	    if (minn[i] == maxx[i]) continue;
	    fop (j,minn[i]+1,maxx[i]) {
	        ans += unions(i,j);
	        vi[j] = true;
	    }
	}
	cout << ans << endl;
}