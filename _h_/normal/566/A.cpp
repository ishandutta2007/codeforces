#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#define rep(i,a,b) for(int i = (int)(a); i < (b); ++i)
using namespace std;
typedef pair<string,bool> p;
typedef pair<int,int> pii;

vector<p> namn;

int lcp(const string &a, const string &b){
	int ans = 0;
	while(ans < min(a.size(),b.size()) && a[ans] == b[ans])
		++ans;
	return ans;
}
bool comp(const int& a,const int& b){return namn[a]<namn[b];}

int main(){
	int n;
	cin >> n;
	namn.resize(2*n);
	rep(i,0,n){
		cin >> namn[i].first;
		namn[i].second = 0;
	}
	rep(i,0,n){
		cin >> namn[i+n].first;
		namn[i+n].second = 1;
	}
	vector<int> q(2*n);
	rep(i,0,2*n)
		q[i] = i;
	sort(q.begin(), q.end(),comp);
	sort(namn.begin(),namn.end());
	vector<int> pek(2*n), bak(2*n);
	rep(i,0,2*n)
		pek[i] = i+1,
		bak[i] = i-1;
	set<pii> lcps;
	rep(i,0,2*n-1){
		if(namn[i].second != namn[i+1].second){
			lcps.insert(pii(-lcp(namn[i].first, namn[i+1].first), i));
		}
	}
	int qual = 0;
	vector<int> svar(2*n);
	rep(i,0,n){
		pii par = *lcps.begin();
		svar[2*i] = par.second;
		svar[2*i+1] = pek[par.second];
		qual -= par.first;
		lcps.erase(lcps.begin());
		int a = bak[par.second];
		int b = pek[pek[par.second]];
		if(a >= 0)
			lcps.erase(pii(-lcp(namn[par.second].first, namn[a].first),a));
		if(b < 2*n)
			lcps.erase(pii(-lcp(namn[pek[par.second]].first, namn[b].first),pek[par.second]));
		if(a >= 0)
			pek[a] = b;
		if(b < 2*n)
			bak[b] = a;
		if(a >= 0 && b < 2*n && namn[a].second != namn[b].second)
			lcps.insert(pii(-lcp(namn[a].first,namn[b].first), a));
	}
	cout << qual << endl;
	rep(i,0,n){
		int a = q[svar[2*i]],
		    b = q[svar[2*i+1]];
		cout << 1+min(a,b) << ' ' << 1+max(a,b)-n << endl;
	}
}