#include <bits/stdc++.h>

using namespace std;

int n;
int a[200000];
vector<int> g[200000];
vector<int> w[200000];
vector<int> st;
vector<long long> pref;
int ans[200000];
int dep[200000];
multiset<int> h[200000];
int pt[200000];

long long sum(int l, int r){
	return pref[r]-(l?pref[l-1]:0);
}

void solve(int v) {
	int ss=(int)st.size();
	st.push_back(v);
	int bigChild=-1;
	for(int i=0; i<(int)g[v].size(); i++) {
			int u=g[v][i];
			dep[u]=dep[v]+1;
			pref.push_back(w[v][i]);
			if(ss>0) pref.back()+=pref[ss-1];
			solve(u);
			if(bigChild==-1||h[pt[u]].size()>h[pt[bigChild]].size())
				bigChild=u;
			pref.pop_back();
		}
	st.pop_back();
	if(g[v].empty())pt[v]=v;
	else pt[v]=pt[bigChild];
	while(!h[pt[v]].empty()&&*h[pt[v]].rbegin()>dep[v])
		h[pt[v]].erase(*h[pt[v]].rbegin());
	for(int u:g[v])
		if(u!=bigChild)
			for(auto it=h[pt[u]].begin(); it!=h[pt[u]].end(); it++)
				if(*it <= dep[v])
					h[pt[v]].insert(*it);
	ans[v]=(int)h[pt[v]].size();
	if(st.empty()||sum(ss-1,ss-1)>a[v])return;
	int bl=0, br=ss-1;
	while(bl < br) {
		int m=(bl+br)>>1;
		if(sum(m,ss-1)<=a[v])br=m;
		else bl=m+1;
	}
	h[pt[v]].insert(dep[st[bl]]);
}

int main() {
	cin>>n;
	for(int i=0; i<n; i++)cin>>a[i];
	int a, b;
	for(int i=1; i<n; i++) {
		cin>>a>>b;
		g[a-1].push_back(i);
		w[a-1].push_back(b);
	}
	solve(0);
	for(int i=0; i<n; i++)cout<<ans[i]<<' ';
}