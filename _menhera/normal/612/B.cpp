#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<iomanip>
using namespace std;

#define REP(i, n) for(int i=0; i<(n); i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)

	
void init()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cout << setprecision(15);
	cout << fixed;
}

template <typename T, typename U>
istream& operator>> (istream &input, pair<T, U> &p)
{
	T t;
	U u;
	input >> t >> u;
	p.first = t;
	p.second = u;
	return input;
}	

template <typename T, typename U>
ostream& operator<< (ostream &output, pair<T, U> &p)
{
	output << p.first << " " << p.second;
	return output;
}	

template <typename T>
ostream& operator<< (ostream &output, vector<T> &t)
{
	for(auto x: t)
		output << x << " ";
	return output;
}



void dec(vector<int> &v)
{
	for(int &t: v)
		t--;
}

vector<int> rearr(vector<int> v)
{
	vector<int> v2;
	v2.resize(v.size());
	REP(i, v.size())
		v2[v[i]] = i;
	return v2;
}

template <typename T>
void in(T &t)
{
	cin >> t;
}

template <typename T>
void in(vector<T> &v, int N)
{
	v.resize(N);
	for(T &t: v)
		in(t);
}


template<typename T>
void out(T &t)
{
	cout << t;
}


template <typename T>
void debug(T &t)
{
	cerr << t;
}


void solve();
int main()
{
	init();
	solve();
	return 0;
}

typedef vector<int> vi;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const long long INFll = 0x3f3f3f3f3f3f3f3fLL;
//Code goes here



void solve()
{
	int N;
	vi V;
	in(N);
	in(V, N);
	dec(V);
	vi X = rearr(V);
	ll ans = 0; 
	for(int i=0; i<N-1; i++)
		ans += abs(X[i] - X[i+1]);
	out(ans);
}