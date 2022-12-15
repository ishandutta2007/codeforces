#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int,int>;

int n,m,la[200001],ra[200001];
char str[200100],tar[200100];

bool solve() {
	set<pair<int,int>> tr;
	int i=0;
	for(int j=0;j<n;j++) {
		if(str[i] != str[j]) {
			tr.insert({i, j-1});
			i = j;
		}
	}
	tr.insert({i, n-1});

	for(int i=0;i<m;i++) {
		int l = la[i], r = ra[i];
		auto it = prev(tr.upper_bound({l, n}));
		if(it->fi < l) {
			tr.insert({it->fi, l-1});
			tr.insert({l, it->se});
			str[l] = str[it->fi];
			tr.erase(it);
			it = prev(tr.upper_bound({l, n}));
		}
		int cnt[2] = {0,};
		while(it != tr.end() && it->fi <= r) {
			if(it->fi <= r && r <= it->se) {
				if(it->se > r) {
					tr.insert({it->fi, r});
					tr.insert({r+1, it->se});
					str[r+1] = str[it->fi];
					tr.erase(it);
					it = prev(tr.upper_bound({r, n}));
				}
			}
			cnt[str[it->fi]] += it->se - it->fi + 1;
			it = tr.erase(it);
		}
		
		if(cnt[0] == cnt[1]) return false;
		str[l] = (cnt[0] > cnt[1]) ? 0 : 1;
		tr.insert({l, r});
	}
	for(auto &it:tr) for(int i=it.fi;i<=it.se;i++) str[i] = str[it.fi];
	for(int i=0;i<n;i++) if(str[i] != tar[i]) return false;
	
	return true;
}

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		scanf("%d%d",&n,&m);
		scanf("%s%s",tar,str);
		for(int i=m-1;i>=0;i--) scanf("%d%d",la+i,ra+i), la[i]-=1, ra[i]-=1;

		for(int i=0;i<n;i++) str[i]-='0', tar[i]-='0';
		puts(solve() ? "YES" : "NO");
	}
	return 0;
}