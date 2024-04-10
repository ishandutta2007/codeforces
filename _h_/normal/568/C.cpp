//#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <string>
#include <cmath>
#include <utility>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <stack>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)
#define rrep(i,a,b) for(int i = int(b)-1; i >= int(a); --i)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

int ix,n,l;
stack<int> st;
vi nums, comps, lwl;
vector<vi> pek;
vector<bool> vis;

int dfs(int a){
	nums[a] = lwl[a] = ix++;
	st.push(a);
	for(auto b : pek[a])
		if(nums[b] == -1)
			lwl[a] = min(lwl[a], dfs(b));
		else if(!vis[b])
			lwl[a] = min(lwl[a], nums[b]);
	if(lwl[a] == nums[a]){
		while(st.top() != a){
			comps[st.top()] = a;
			vis[st.top()] = 1;
			st.pop();
		}
		vis[a] = 1;
		comps[a] = a;
		st.pop();
	}
	return lwl[a];
}

void scc(){
	ix = 0;
	nums.assign(n,-1);
	comps.assign(n,-1);
	lwl.assign(n,0);
	vis.assign(n,0);
	rep(i,0,n)
		if(nums[i] == -1)
			l = ix,
			dfs(i);
}

bool sat(){
	n = pek.size();
	int c = n/2;
	scc();
	rep(i,0,c)
		if(comps[i] == comps[i+c])
			return 0;
	return 1;
}

int main(){
	cin.sync_with_stdio(0);
	string vc, s;
	int N,m;
	cin >> vc >> N >> m;
	vector<vi> rules(2*N);
	rep(i,0,m){
		int p1, p2;
		char t1, t2;
		cin >> p1 >> t1 >> p2 >> t2;
		--p1, --p2;
		if(t1 == 'C')
			p1 += N;
		if(t2 == 'C')
			p2 += N;
		rules[p1].pb(p2);
		rules[(p2+N)%(2*N)].pb((p1+N)%(2*N));
	}
	cin >> s;
	if(!count(vc.begin(),vc.end(),'C')){
		rep(i,0,N)
			for(auto j : rules[i])
				if(j >= N){
					cout << -1 << endl;
					return 0;
				}
		cout << s << endl;
		return 0;
	}
	if(!count(vc.begin(),vc.end(),'V')){
		rep(i,N,2*N)
			for(auto j : rules[i])
				if(j < N){
					cout << -1 << endl;
					return 0;
				}
		cout << s << endl;
		return 0;
	}
	rrep(i,0,N+1){
		pek = rules;
		rep(j,0,i){
			if(vc[s[j]-'a'] == 'V')
				pek[j+N].pb(j);
			else
				pek[j].pb(N+j);
		}
		if(i != N){
			if(s[i]-'a'+1 >= vc.size())
				continue;
			char c = vc[s[i]-'a'+1];
			bool b = 0;
			for(int k = s[i]-'a'+2; k < vc.size(); ++k)
				if(vc[k] != c)
					b = 1;
			if(!b)
				if(c == 'V')
					pek[i+N].pb(i);
				else
					pek[i].pb(i+N);
		}
		if(sat()){
			string ans = s.substr(0,i);
			for(int j = i; j < N; ++j){
				char cand = i == j ? s[i]+1 : 'a';
				if(vc[cand-'a'] == 'V')
					pek[j+N].pb(j);
				else
					pek[j].pb(j+N);
				if(sat())
					ans.pb(cand);
				else{
					char bra = cand;
					while(vc[bra-'a'] == vc[cand-'a'])
						++bra;
					ans.pb(bra);
					if(vc[cand-'a'] == 'C')
						pek[j+N].pb(j),
						pek[j].pop_back();
					else
						pek[j].pb(j+N),
						pek[j+N].pop_back();
				}
			}
			cout << ans << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}