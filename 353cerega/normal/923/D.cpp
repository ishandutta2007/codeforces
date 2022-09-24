#include<bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg

const int maxn = 1e5 + 5;

string s, t;
int ns, nt;
int ps[maxn], pt[maxn];
int goods[maxn], goodt[maxn];
int ans[maxn];

signed main(){
	sync;
	cin >> s;
	cin >> t;
	ns = s.length(); nt = t.length();
	F(i, 0, ns){
		ps[i] = (i == 0) ? 0 : ps[i - 1];
		if(s[i] != 'A')++ps[i];
	}
	F(i, 0, nt){
		pt[i] = (i == 0) ? 0 : pt[i - 1];
		if(t[i] != 'A')++pt[i];
	}
	int la = -1;
	F(i, 0, ns){
		if(s[i] != 'A')la = i;
		goods[i] = la;
	}
	la = -1;
	F(i, 0, nt){
		if(t[i] != 'A')la = i;
		goodt[i] = la;
	}
	int q;
	cin >> q;
	F(i, 0, q){
		int ls, rs, lt, rt;
		cin >> ls >> rs >> lt >> rt;
		--ls; --rs; --lt; --rt;
		int cnts = ps[rs] - (ls == 0 ? 0 : ps[ls - 1]);
		int cntt = pt[rt] - (lt == 0 ? 0 : pt[lt - 1]);
		if(cnts > cntt){ans[i] = 0; cont;}
		if(cnts%2 != cntt%2){ans[i] = 0; cont;}
		int da = (cntt - cnts)/2;
		int ss, st;
		ss = rs + 1 - max(ls, goods[rs]);
		st = rt + 1 - max(lt, goodt[rt]);
		bool can_make = false;
		//F(j, 0, 2){
		//	if(ss >= st && ss >= j && j <= da && (ss + 3 - j)%3 == st%3)can_make = true;
		//}
		if(ss >= st && (da >= 1 || (da == 0 && ss%3 == st%3)))can_make = true;
		if(can_make)ans[i] = 1;
		else ans[i] = 0;
	}
	F(i, 0, q)cout << ans[i];
	ret 0;
}