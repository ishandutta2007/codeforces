#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	int n;
	cin >> n;
	string t;
	cin >> t;
	vector <int> s,g;
	int f=1;
	char a=t[0];
	if (a=='G') f=0;
	int now=1;
	fop (i,1,n) {
		if (a==t[i]) {
			now++;
		} else {
		    if (a=='S') s.pb(now);
		    else g.pb(now);
			a=t[i];
			now=1;
		}
    }
    if (a=='S') s.pb(now);
    else g.pb(now);
	int maxx=0;
	if (f==0) {
	    fop (i,0,s.size()) {
	        if (i+1<g.size() && s[i]==1) maxx=max(maxx,g[i]+g[i+1]);
	    }
	} else {
	    fop (i,1,s.size()) {
	        if (i<g.size() && s[i]==1) maxx=max(maxx,g[i-1]+g[i]);
	    }
	}
	maxx+=(g.size()>2);
	fop (i,0,g.size()) {
	    maxx=max(maxx,g[i]+(g.size()>1));
	}
	cout << maxx << endl;
	return 0;
}