#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int ind[MAXN];
vector<piii> vec;

bool cmp(int i, int j){ return A[i]<A[j];}

void check(int id){
	int tmp=A[id];
	A[id]=inf;
	sort(ind+1, ind+n+1, cmp);
	n--;
	bool f=1;
	for (int i=1; i<n; i++) if (A[ind[i+1]]-A[ind[i]]!=A[ind[2]]-A[ind[1]]) f=0;
	if (f){
		cout<<id<<'\n';
		exit(0);
	}
	n++;
	A[id]=tmp;
	sort(ind+1, ind+n+1, cmp);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], ind[i]=i;
	if (n<=3) kill(1)
	sort(ind+1, ind+n+1, cmp);
	check(ind[1]);
	check(ind[n]);
	/*
	bool f=1;
	for (int i=1; i<n; i++) if (A[ind[i+1]]-A[ind[i]]!=A[ind[2]]-A[ind[1]]) f=0;
	if (f) kill(ind[1])
	*/
	for (int i=1; i<n; i++) vec.pb({A[ind[i+1]]-A[ind[i]], {ind[i], ind[i+1]}});
	sort(all(vec));
	if (vec[0].first+vec[1].first!=vec[2].first) kill(-1)
	int del=vec[0].second.first;
	if (del!=vec[1].second.first && del!=vec[1].second.second){
		del=vec[0].second.second;
		if (del!=vec[1].second.first && del!=vec[1].second.second) kill(-1)
	}
	A[del]=inf;
	sort(ind+1, ind+n+1, cmp);
	n--;
	for (int i=1; i<n; i++) if (A[ind[i+1]]-A[ind[i]]!=A[ind[2]]-A[ind[1]]) del=-1;
	kill(del)
	
	return 0;
}