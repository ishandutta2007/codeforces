#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
typedef pair<int,int> pii;
typedef vector<int> vi;
int main(){
	int n,s,a;
	set<pii> cells;
	scanf("%d%d",&n,&s);
	rep(i,1,n+1){
		scanf("%d",&a);
		cells.insert(pii(a,i));
	}
	vector<vi> gs;
	int pr = -2e9;
	for(pii p : cells){
		if(p.first != pr){
			if(!gs.empty()){
				sort(allof(gs.back()));
			}
			gs.push_back(vi(0));
		}
		pr = p.first;
		gs.back().push_back(p.second);
	}
	sort(allof(gs.back()));
	vi bg(n+1), en(n+1), pb(n+1), pe(n+1), vf(n+1), vp(n+1);
	rep(i,0,gs.size()){
		if(i){
			for(int pos : gs[i]){
				bg[pos] = 1e9;
				for(int pr : gs[i-1]){
					int d = en[pr]+min((n+pr-pos)%n,(n+pos-pr)%n);
					if(bg[pos] > d){
						pb[pos] = pr;
						bg[pos] = d;
					}
				}
			}
		} else {
			for(int pos : gs[0]){
				bg[pos] = min((n+pos-s)%n,(n+s-pos)%n);
				pb[pos] = s;
			}
		}
		int m = gs[i].size();
		rep(j,0,m){
			int pos = gs[i][j];
			int fr  = gs[i][(j+1)%m];
			int pr  = gs[i][(j-1+m)%m];
			vf[pos] = fr;
			vp[pos] = pr;
			int df = bg[fr]+(n+pos-fr)%n;
			int dp = bg[pr]+(n+pr-pos)%n;
			en[pos] = min(df,dp);
			pe[pos] = df<dp ? fr : pr;
		}
	}
	int ans = 1e9, pos, ix = n;
	vi v(n+1);
	for(int ps : gs.back()){
		if(ans > en[ps]){
			ans = en[ps];
			pos = ps;
		}
	}
	printf("%d\n",ans);
	while(ix > 0){
		int j = pos;
		if(pe[pos] == vf[pos]){
			do {
				v[ix--] = j;
				j = vp[j];
			} while(j != pos);
		} else {
			do {
				v[ix--] = j;
				j = vf[j];
			} while (j != pos);
		}
		pos = pb[pe[pos]];
	}
	v[0] = s;
	rep(i,0,n){
		int d = (n+v[i+1]-v[i])%n;
		if(d > n-d)
			printf("%d\n",d-n);
		else
			printf("+%d\n",d);
	}
}