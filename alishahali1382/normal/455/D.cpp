#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
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
const int MAXN = 100010, SQ=320;

int n, m, k, u, v, x, y, t, l, r, ans, type;
int A[MAXN];
deque<int> dq[SQ];
int cnt[SQ][MAXN];

void build(){
	for (int i=0; i<n; i++){
		dq[i/SQ].pb(A[i]);
		cnt[i/SQ][A[i]]++;
	}
}

void relax(){
	for (int i=0; i<SQ-1; i++){
		if (dq[i].size()==0) return ;
		while (dq[i].size()<SQ && dq[i+1].size()){
			dq[i].pb(dq[i+1].front());
			cnt[i][dq[i+1].front()]++;
			cnt[i+1][dq[i+1].front()]--;
			dq[i+1].pop_front();
		}
		while (dq[i].size()>SQ){
			dq[i+1].push_front(dq[i].back());
			cnt[i+1][dq[i].back()]++;
			cnt[i][dq[i].back()]--;
			dq[i].pop_back();
		}
	}
}

int del(int ind){ // 0-base
	int i=ind/SQ;
	ind%=SQ;
	int res=dq[i][ind];
	for (int j=ind+1; j<dq[i].size(); j++) swap(dq[i][j], dq[i][j-1]);
	dq[i].pop_back();
	cnt[i][res]--;
	relax();
	return res;
}

int add(int ind, int x){ // 0-base
	int i=ind/SQ;
	ind%=SQ;
	dq[i].pb(x);
	for (int j=dq[i].size()-1; j>ind; j--) swap(dq[i][j], dq[i][j-1]);
	cnt[i][x]++;
}

int get(int l, int r, int k){
	int res=0;
	r++;
	while (l<r){
		if (l%SQ==0 && l+SQ<r){
			res+=cnt[l/SQ][k];
			l+=SQ;
		}
		else{
			res+=(dq[l/SQ][l%SQ]==k);
			l++;
		}
	}
	return res;
}

void print(){
	for (int i=0; i<SQ; i++){
		for (int j:dq[i]) cerr<<j<<' ';
		if (i==SQ-1) cerr<<'\n';
		else cerr<<" |  ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++) cin>>A[i];
	build();
	
	cin>>m;
	while (m--){
		relax();
		//print();
		cin>>type>>l>>r;
		l=((l+ans-1)%n)+1;
		r=((r+ans-1)%n)+1;
		if (l>r) swap(l, r);
		l--;
		r--;
		
		if (type==1){
			if (l==r) continue ;
			add(l, del(r));
			continue ;
		}
		cin>>k;
		k=((k+ans-1)%n)+1;
		ans=get(l, r, k);
		cout<<ans<<'\n';
	}
	
	return 0;
}
/*
7
6 6 2 7 4 2 5
2
1 3 6
2 2 4 2


*/