#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <cstdlib>

#define var(x) #x
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sqr(x) (x)*(x)
#define assert(x) if (!(x)){cout << "Assertion failed" << endl; cerr << "Assertion failed" << endl; exit(132);}
#define all(x) x.begin(), x.end()
#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define endl '\n'
#define sp ' '
#define elif else if

using namespace std;

typedef long long int64;
typedef unsigned long long lint;
typedef long double ld;
typedef long double extended;

template<typename type>
inline static void _cutedebug(const type &a){
	cerr << a;
}
template<typename type1, typename type2>
inline static void _cutedebug(const pair<type1, type2> &a){
	cerr << "("; _cutedebug(a.fs); cerr << ", "; _cutedebug(a.sc); cerr << ")";
}
template<typename type>
inline static void _cutedebug(const vector<type> &a){
	cerr << "{";
	bool flag = true;
	for (typename vector<type>::const_iterator i = a.begin(); i != a.end(); i++){
		if (flag)
			flag = false;
		else
			cerr << ", ";
		_cutedebug(*i);
	}
	cerr << "}";
}
#ifdef CUTEBMAING
template<typename type>
inline static void _cutedebug_(const type &a, string name, int ln = __LINE__){
	cerr << "Line " << ln << " : " << name << " = "; _cutedebug(a); cerr << ";" << endl;
}
#endif
#ifndef CUTEBMAING
template<typename type>
inline static void _cutedebug_(const type &a, string name, int ln = __LINE__){;}
#endif
#define debug(x) _cutedebug_(x, var(x), __LINE__)

const char* fin = "input.txt";
const char* fout = "output.txt";

const int inf = (1 << 30);
const int64 linf = (int64(1) << 61);
const int cc = 700;
const int cmax = 200500;
const int kmax = 200000;

int n, t;
int a[kmax];
int ll[kmax], rr[kmax];
int ps[kmax], sa[kmax];

bool cmp(int a, int b){
    return (ps[a] < ps[b]) || ((ps[a] == ps[b]) && (rr[a] < rr[b])) || ((ps[a] == ps[b] && rr[a] == rr[b]) && ll[a] < ll[b]);
}

int64 val = 0;
vector<int> c;
int l = 0, r = -1;
int64 ans[kmax];
int64 sq[cmax];
int cnt = 0;
int out[cmax];

#define add(x) {val -= sq[c[(x)]] * out[(x)]; ++c[(x)]; val += sq[c[(x)]] * out[(x)];}
#define rem(x) {val -= sq[c[(x)]] * out[(x)]; --c[(x)]; val += sq[c[(x)]] * out[(x)];}

void make_zip(){
	vector<int> sa(n);
	for (int i = 0; i < n; i++)
		sa[i] = a[i];
	sort(sa.begin(), sa.end());
	map<int, int> in;
	int cur = 0;
	for (int i = 0; i < n; i++){
		if (in.find(sa[i]) == in.end())
			++cur;
		in[sa[i]] = cur - 1;
		out[cur-1] = sa[i];
	}
	for (int i = 0; i < n; i++)
		a[i] = in[a[i]];
}

int main()
{
    #ifdef CUTEBMAING
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
    #endif
    for (int i = 0; i <= 200000; i++)
        sq[i] = sqr(1ll * i);
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    make_zip();
    for (int i = 0; i < t; i++){
        scanf("%d %d", &ll[i], &rr[i]); --ll[i]; --rr[i];
    }
    for (int i = 0; i < t; i++)
        ps[i] = ll[i] / cc;
    for (int i = 0; i < t; i++)
        sa[i] = i;
    sort(sa, sa+t, cmp);
    for (int i = 0; i < t; i++){
        int cur = sa[i];
        if (i == 0 || ps[cur] != ps[sa[i-1]])
            l = 0, r = -1, c.assign(cmax, 0), val = 0;
        while (r < rr[cur]){
            int cr = ++r;
            add(a[cr]);
        }
        while (l < ll[cur]){
            int cr = l++;
            rem(a[cr]);
        }
        while (l > ll[cur]){
            int cr = --l;
            add(a[cr]);
        }
        ans[cur] = val;
    }
    for (int i = 0; i < t; i++)
        printf("%I64d\n", ans[i]);
    return 0;
}