#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s, sub;
	cin >> s >> sub;
	if(s == "01"){
		cout << 0 << endl;
		return 0;
	}
	int cnt[10] = {};
	for(char c : s) ++cnt[c-'0'];
	for(char c : sub) --cnt[c-'0'];
	int dig = s.size();
	while(dig + ceil(log10(dig)) > s.size()) dig--;
	while(dig){
		--cnt[dig%10];
		dig /= 10;
	}
	string cnd1 = sub;
	int d = sub[0]-'0';
	rep(i,0,d+1) rep(_,0,cnt[i]) cnd1.pb(i+'0');
	rep(i,d+1,10) rep(_,0,cnt[i]) cnd1.pb(i+'0');
	string cnd2;
	rep(i,1,10){
		if(cnt[i]){
			cnd2.pb(i+'0');
			--cnt[i];
			break;
		}
	}
	if(cnd2.empty()){
		cout << cnd1 << endl;
		return 0;
	}
	bool gt;
	rep(i,1,sub.size()) if(sub[i] != sub[0]){
		gt = sub[i] > sub[0];
		break;
	}
	rep(i,0,d) rep(_,0,cnt[i]) cnd2.pb(i+'0');
	if(gt){
		rep(_,0,cnt[d]) cnd2.pb(d+'0');
		cnd2 = cnd2 + sub;
	} else {
		cnd2 = cnd2 + sub;
		rep(_,0,cnt[d]) cnd2.pb(d+'0');
	}
	rep(i,d+1,10) rep(_,0,cnt[i]) cnd2.pb(i+'0');
	if(sub[0] == '0') cout << cnd2 << endl;
	else cout << min(cnd1,cnd2) << endl;
}