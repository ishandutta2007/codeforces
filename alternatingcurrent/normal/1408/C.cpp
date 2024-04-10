#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, l;
int a[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> l;
		for(int i = 1; i <= n; i++) cin >> a[i];
		a[0] = 0, a[n+1] = l;
		int lef = 1, rig = n;
		double t_lef, t_rig;
		t_lef = t_rig = 0.00;
		while(lef <= rig){
			double nxt_t_lef = t_lef + 1.00 * (a[lef] - a[lef - 1]) / (double)(lef);
			double nxt_t_rig = t_rig + 1.00 * (a[rig + 1] - a[rig]) / (double)(n + 1.00 - rig);
			if(nxt_t_lef < nxt_t_rig) lef++, t_lef = nxt_t_lef;
			else rig--, t_rig = nxt_t_rig;
		}
		double dist = a[lef] - a[rig];
		double mx_t = max(t_lef, t_rig);
		dist -= (mx_t - t_lef) * (double)(lef);
		dist -= (mx_t - t_rig) * (double)(n + 1.00 - rig);
		mx_t += (1.00 * dist / (double)(lef + n + 1.00 - rig));
		cout << fixed << setprecision(12) << mx_t << endl; 
	} 
	return 0;
}