#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second 
#define REP(i,n) for (int i = 0; i<n; i++)
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define MX(a,b) a = max(a, (__typeof__(a)) (b))
#define MN(a,b) a = min(a, (__typeof__(a)) (b))
#ifdef BALBIT
#define debug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS()
#else
#define IOS() ios::sync_with_stdio(0), cin.tie(0)
#define debug(x)
#define endl '\n'
#endif

int h[11][11];
double ev[11][11];

pii nxt(pii a){
	if (a.f%2==0){ // Going left
		if(a.s==0) {
			a.f--;
		}else{
			a.s--;
		}
	}else{
		if(a.s==9){
			a.f--;
		}else{
			a.s++;
		}
	}
	return a;
}

signed main(){
	IOS();
	REP(i,10) REP(j,10) cin>>h[i][j];
	pii at = {9,0};
	vector<pii> v;
	while (at != make_pair(-1,0)){
		v.pb(at); at = nxt(at);
	}
	reverse(ALL(v));
	double sx = (1/6.0);
	for (pii i : v){
		pii j = i;
		int nmv = 0;
		for (int it = 0; it<6 && j != make_pair(0,0); it++){
			j = nxt(j); nmv++;
			ev[i.f][i.s] += (1+min(ev[j.f-h[j.f][j.s]][j.s], ev[j.f][j.s]))*sx;
		}
		if (nmv==0) continue;
		if (nmv==6) {
			
		}else{
			ev[i.f][i.s] += (6-nmv)*sx;
			ev[i.f][i.s] = ev[i.f][i.s] * 6 / nmv;
		}
		
//		cout<<i.f<<' '<<i.s<<endl;
		debug(ev[i.f][i.s]);
		
	}
	cout<<fixed<<setprecision(20)<<ev[9][0]<<endl;
	
}