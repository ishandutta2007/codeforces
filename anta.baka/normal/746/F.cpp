#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define SZ(x) (int)(x).size()

typedef pair<int,int> pii;

const int N = 200000;

set<pii> full, half; // full=0, half=1
int Time=0,Ples=0;
int n, w, k;
int a[N], t[N];
int which[N];

void add(int id) {
	Ples += a[id];
	if(SZ(half)<w) {
		Time += (t[id]+1)/2;
		half.insert(mp(t[id],id));
		which[id]=1;
		return;
	}
	if(t[id]>half.begin()->fi) {
		pii mov = *half.begin();
		half.erase(half.begin());
		which[mov.se]=0;
		which[id]=1;
		full.insert(mov);
		half.insert(mp(t[id],id));
		Time += mov.fi - (mov.fi+1)/2 + (t[id]+1)/2;
		return;
	}
	which[id]=0;
	Time += t[id];
	full.insert(mp(t[id],id));
}

void erase(int id) {
	Ples -= a[id];
	if(which[id]==0) {
		Time -= t[id];
		full.erase(mp(t[id],id));
		return;
	}
	Time -= (t[id]+1)/2;
	half.erase(mp(t[id],id));
	if(full.empty())
		return;
	pii nw = *full.rbegin();
	Time += (nw.fi+1)/2 - nw.fi;
	full.erase(full.find(nw));
	which[nw.se]=1;
	half.insert(nw);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> w >> k;
	for(int i=0; i<n; i++)cin>>a[i];
	for(int i=0; i<n; i++)cin>>t[i];

	int res = 0;
	for(int lf = 0, rg = -1; lf < n; lf++) {
		if(lf) erase(lf-1);
		if(Time <= k)
			res = max(res, Ples);
		while(rg < n-1 && Time <= k) {
			rg++;
			add(rg);
			if(Time <= k)
				res = max(res, Ples);
		}
	}
	cout << res;
}