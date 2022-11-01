#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>


#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> (v)[i];}while(0)
#define all(c) (c).begin(),(c).end()

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

typedef pair<Pii,bool> P;

int n,k;
string wl[2];

int d[2][100000];

int main()
{
	//freopen("in.txt","r",stdin);

	cin>>n>>k>>wl[0]>>wl[1];
	memset(d,0x7F,sizeof(d));

	d[0][0] = 0;
	priority_queue<P,vector<P>, greater<P> > q;
	q.push(P(Pii(0,0),false));
	while(!q.empty()){
		int cost = q.top().first.first;
		int pos = q.top().first.second;
		bool right = q.top().second;
		q.pop();

		if(d[right][pos] < cost) continue;
		int nexts[] = {pos + 1, pos - 1, pos + k};
		bool next_right[] = {right,right,!right};
		for (int i = 0; i < 3; i++){
			int nt = nexts[i];
			bool nt_rt = next_right[i];
			if(nt >= n){
				puts("YES");
				return 0;
			}
			if(nt <= cost || wl[nt_rt][nt] == 'X') continue;
			if(d[nt_rt][nt] <= cost + 1) continue;
			d[nt_rt][nt] = cost + 1;
			q.push(P(Pii(cost + 1,nt),nt_rt));
		}
	}

	puts("NO");

	return 0;
}