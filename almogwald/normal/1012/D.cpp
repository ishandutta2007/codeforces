#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <math.h> 
#include <iomanip>
using namespace std;
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define forrb(i,a,b,c) for(int i=a;i>b;i-=c)
#define fori(i,n) forr(i,0,n,1)
#define forib(i,n) forrb(i,n-1,-1,1)
#define forn(i,n) forr(i,1,n,1)
#define fornb(i,n) forrb(i,n-1,0,1)
#define fort(i,m,n) forr(i,m,n,1)
#define fortb(i,m,n) forrb(i,n-1,m-1,1)
#define forin(i,arr) fori(i,arr.size())
#define forinb(i,arr) forib(i,arr.size())
#define into(i) cin >> i;
#define def(i) int i; into(i)
#define deft(t,i) t i; into(i)
#define defn def(n)
#define defp def(p)
#define defm def(m)
#define defk def(k)
#define defa def(a)
#define defb def(b)
#define defc def(c)
#define defd def(d)
#define vec(a) vector<a>
#define co cout <<
#define out(a) cout << a <<' ';
#define el << endl;
#define outv(arr,n) fori(i,n){out(arr[i])} co "" el
#define cas(p) co "Case #" << p+1 <<": ";
#define ex return 0; 
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define con continue;
#define br break;
#define maxi 1000000013
#define mod %998244353;
#define wne(arr) while(!arr.empty())
#define all(arr) arr.begin(),arr.end()
#define _230 1073741824
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<int, int> point;
typedef pair<point, point> poin;
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
void cruel(string s, string t, vector<point> &out) {
	int n = s.size() + t.size() + 2;
	veci sr(n);
	int srealength = 0;
	forin(i, s) {
		if ((s[i] - 'a') % 2 != srealength % 2) {
			srealength++;
		}
		sr[srealength]++;
	}
	veci tr(n);
	int trealength = 0;
	forin(i, t) {
		if ((t[i] - 'a') % 2 != trealength % 2) {
			trealength++;
		}
		tr[trealength]++;
	}
	int i = 0;
	int j = 0;
	if (sr[0] == 0) {
		i++;
	}
	if (tr[0] == 0) {
		j++;
	}
	if (i == j) {
		if (srealength <= trealength) {
			out.push_back(make_pair(0, tr[j]));
			sr[i] += tr[j];
			j++;
		}
		else {
			out.push_back(make_pair(sr[i], 0));
			tr[j] += sr[i];
			i++;
		}
	}
	while ((i < srealength) || (j < trealength)) {
		out.push_back(make_pair(sr[i], tr[j]));
		tr[j + 1] += sr[i];
		sr[i + 1] += tr[j];
		i++;
		j++;
	}
}
void cutl(string s, string t, int num, vector<point> &out) {
	int i = 0;
	while (num > 0) {
		i++;
		if (s[i] != s[i - 1]) {
			num--;
		}
	}
	t = s.substr(0, i)+t;
	s = s.substr(i);
	out.push_back(make_pair(i, 0));
	cruel(s, t, out);
}
void cutlp(string s, string t, int num, vector<point> &out) {
	int i = 0;
	while (num > 0) {
		i++;
		if (s[i] != s[i - 1]) {
			num--;
		}
	}
	int j = 0;
	num = 1;
	while (num > 0) {
		j++;
		if (t[j] != t[j - 1]) {
			num--;
		}
	}
	string tt = s.substr(0, i) + t.substr(j);
	string ss = t.substr(0, j) + s.substr(i);
	out.push_back(make_pair(i, j));
	cruel(ss, tt, out);
}
void cutr(string s, string t, int num, vector<point> &out) {
	int i = 0;
	while (num > 0) {
		i++;
		if (t[i] != t[i - 1]) {
			num--;
		}
	}
	s = t.substr(0, i)+s;
	t = t.substr(i);
	out.push_back(make_pair(0, i));
	cruel(s, t, out);
}
void cutrp(string s, string t, int num, vector<point> &out) {
	int i = 0;
	while (num > 0) {
		i++;
		if (t[i] != t[i - 1]) {
			num--;
		}
	}
	int j = 0;
	num = 1;
	while (num > 0) {
		j++;
		if (s[j] != s[j - 1]) {
			num--;
		}
	}
	string tt = s.substr(0, j) + t.substr(i);
	string ss = t.substr(0, i) + s.substr(j);
	out.push_back(make_pair(j, i));
	cruel(ss, tt, out);
}
int main() {
	ios::sync_with_stdio(false);
	deft(string, s)
	deft(string, t)
		int n = s.size() + t.size() + 2;
	veci sr(n);
	int srealength = 0;
	forin(i, s) {
		if ((s[i] - 'a') % 2 != srealength % 2) {
			srealength++;
		}
		sr[srealength]++;
	}
	veci tr(n);
	int trealength = 0;
	forin(i, t) {
		if ((t[i] - 'a') % 2 != trealength % 2) {
			trealength++;
		}
		tr[trealength]++;
	}
	vector<point> out;
	cruel(s, t, out);
	if (out.size() == 0) {
		co 0 el
			ex
	}
	vector<point> outi1;
	vector<point> outi2;
	vector<point> outi3;
	vector<point> outi4;
	vector<point> outi5;
	vector<point> outi6;
	if (srealength >= trealength) {
		int averge = (srealength - trealength) / 2;
		cutl(s, t, averge - 1, outi1);
		cutl(s, t, averge , outi2);
		cutl(s, t, min(averge + 1, srealength - 1), outi3);
		cutlp(s, t, averge, outi4);
		cutlp(s, t, min(averge + 1, srealength-1), outi5);
		cutlp(s, t, min(averge + 2, srealength - 1), outi6);
	}
	if (srealength+1 <= trealength) {
		int averge = (trealength - srealength) / 2;
		cutr(s, t, averge - 1, outi1);
		cutr(s, t, averge, outi2);
		cutr(s, t, min(averge + 1, trealength-1), outi3);
		cutrp(s, t, averge, outi4);
		cutrp(s, t, min(averge + 1, trealength-1), outi5);
		cutrp(s, t, min(averge + 2, trealength-1), outi6);
	}
	if (outi1.size()<out.size()) {
		out = outi1;
	}
	if (outi2.size()<out.size()) {
		out = outi2;
	}
	if (outi3.size()<out.size()) {
		out = outi3;
	}
	if (outi4.size()<out.size()) {
		out = outi4;
	}
	if (outi5.size()<out.size()) {
		out = outi5;
	}
	if (outi6.size()<out.size()) {
		out = outi6;
	}
	co out.size() el
		
	forin(i, out) {
		co out[i].first <<' '<< out[i].second el
	}
	ex
}