#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

struct Seg{
	int c,l,r;
	Seg(int c_ = 0, int l_ = 0, int r_ = 0):c(c_),l(l_),r(r_){}
};

bool operator<(const Seg &a, const Seg &b){
	return a.l < b.l;
}

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int cnt[10][10] = {};
	set<Seg> s;
	int pr = -1;
	rep(i,0,n){
		char ch;
		scanf(" %c ",&ch);
		s.insert(Seg(ch-'a',i,i+1));
		if(pr != -1){
			++cnt[pr][ch-'a'];
		}
		pr = ch-'a';
	}
	rep(_,0,m){
		int tp = -1;
		scanf(" %d ",&tp);
		if(tp == 1){
			int l,r,c;
			char ch;
			scanf("%d%d %c",&l,&r,&ch);
			--l;
			c = ch-'a';
			auto it = s.upper_bound(Seg(0,l,0));
			--it;
			auto jt = s.lower_bound(Seg(0,r,0));
			--jt;
			auto kt = it;
			bool ja = 1;
			if(kt != s.begin()) --kt, ja = 0;
			do {
				if(ja){
					cnt[kt->c][kt->c] -= (kt->r)-(kt->l)-1;
				}
				auto pl = kt;
				++pl;
				if(pl != s.end()){
					cnt[kt->c][pl->c]--;
				}
				ja = 1;
			} while(kt ++ != jt);
			Seg i = *it;
			Seg j = *jt;
			s.erase(it,++jt);
			if(i.l < l){
				s.insert(Seg(i.c,i.l,l));
			}
			s.insert(Seg(c,l,r));
			if(j.r > r){
				s.insert(Seg(j.c,r,j.r));
			}
			if(i.l < l){
				it = s.find(Seg(i.c,i.l,l));
			} else {
				it = s.find(Seg(c,l,r));
			}
			if(j.r > r){
				jt = s.find(Seg(j.c,r,j.r));
			} else {
				jt = s.find(Seg(c,l,r));
			}
			kt = it;
			ja = 1;
			if(kt != s.begin()) --kt, ja = 0;
			do {
				if(ja){
					cnt[kt->c][kt->c] += (kt->r)-(kt->l)-1;
				}
				auto pl = kt;
				++pl;
				if(pl != s.end()){
					cnt[kt->c][pl->c]++;
				}
				ja = 1;
			} while(kt ++ != jt);
		} else {
			int p[10];
			char ch;
			rep(i,0,k){
				scanf("%c",&ch);
				p[i] = ch-'a';
			}
			int ans = 1;
			rep(i,0,k) rep(j,0,i+1)
				ans += cnt[p[i]][p[j]];
			printf("%d\n",ans);
		}
	}
}