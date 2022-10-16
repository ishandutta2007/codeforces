/*
 * 	Just close your eyes
 * 		The sun is going down
 * 			You'll be alright...
 * 				No one can hurt you now
 * 					Come, morning light...
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1e9+7;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s;
int a[26][400000];
bool lazy[26][400000];
bool lazyv[26][400000];
void pushdown(int i,int seg, int ll, int rr) {
	if(lazy[i][seg]) {
		lazy[i][seg*2]=1;
		lazy[i][seg*2+1]=1;
		lazyv[i][seg*2]=lazyv[i][seg];
		lazyv[i][seg*2+1]=lazyv[i][seg];
		a[i][seg*2]=lazyv[i][seg]*((rr+ll)/2+1-ll);
		a[i][seg*2+1]=lazyv[i][seg]*(rr-(rr+ll)/2);
		lazy[i][seg]=0;
	}
}
int sum(int i, int seg, int l, int r, int ll, int rr) {
	if(r<ll||l>rr||l>r)
		return 0;
	if(r>=rr&&ll>=l) {
		return a[i][seg];
	}
	pushdown(i, seg, ll, rr);
//	deb<<ll<<" "<<rr<<endl;
	return sum(i,seg*2,l,r,ll,(ll+rr)/2)+sum(i,seg*2+1,l,r,1+(ll+rr)/2,rr);
}
void assign(int i, int seg, int l, int r, int ll, int rr, int val) {
	if(r<ll||l>rr||l>r)
		return;
	if(r>=rr&&ll>=l) {
		lazy[i][seg]=1;
		lazyv[i][seg]=val;
		a[i][seg]=(rr-ll+1)*val;
		return;
	}
	pushdown(i,seg,ll,rr);
	assign(i,seg*2,l,r,ll,(ll+rr)/2,val);
	assign(i,seg*2+1,l,r,(ll+rr)/2+1,rr,val);
	a[i][seg]=a[i][seg*2]+a[i][seg*2+1];
}
int summ[26];
void solve()
{
	int n,q;
	cin>>n>>q>>s;
	s='o'+s;
	for(int i=1; i<=n; i++)
		assign((s[i]-'a'),1,i,i,1,n,1);
	while(q--) {
		int l,r,k;
		cin>>l>>r>>k;
		for(int i=0; i<26; i++)
			summ[i]=sum(i,1,l,r,1,n);
		for(int i=0; i<26; i++)
			assign(i,1,l,r,1,n,0);
		if(k==1) {
			for(int i=0; i<26; i++) {
				assign(i,1,l,l+summ[i]-1,1,n,1);
				l+=summ[i];
			}
		} else {
			for(int i=25; i>=0; i--) {
				assign(i,1,l,l+summ[i]-1,1,n,1);
				l+=summ[i];
			}
		}
	}
	string ans="";
	for(int i=1; i<=n; i++)
		for(int j=0; j<26; j++)
			if(sum(j,1,i,i,1,n))
				ans+=(char)(j+'a');
	cout<<ans<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	auto clk=clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}