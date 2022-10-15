#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")

#define int ll

#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;



const int maxn = 1e5+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll pow(ll a, ll n){ // a^n % mod
	ll re=1;
	while (n>0){
		if (n&1) re = re*a %mod;
		a = a*a %mod;
		n>>=1;
	}
	return re;
}

ll inv (ll b){
	if (b==1) return b;
	return (mod-mod/b) * inv(mod%b) % mod;
}

map<int, int> num, sum;
vector<int> b;
vector<int> orig(maxn);
int n, A, cf, cm, m; 
int border=inf;

bool can(int val, int M){
	if (val<=b[0]) return 1;
	int at= *prev(lower_bound(ALL(b), val));
	if (val > b.back()) at = b.back();
	if (at> border) at = border;
	int nn = num[at], ss = sum[at];
	int need = val*nn - ss;
	if (need>M) return 0;
	return 1;
}

int bs(int M){
	int l = 0, r = A+1;
	int re = 0;
	while (l!=r){
		int mid = (l+r)/2;
		if (can(mid, M)){
			MXTO(re, mid);
			l = mid+1;
		}else {
			r = mid;
		}
	}
	return re;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>A>>cf>>cm>>m;
    vector<int> a(n);
    vector<pii> tmp(n);
    REP(i,n) {cin>>a[i]; tmp[i] = {a[i],i}; orig[i]=a[i]; num[a[i]]++; sum[a[i]]+=a[i];}
    sort(ALL(tmp), greater<pii>());
    sort(ALL(a));
    b=a;
	b.erase( unique( b.begin(), b.end() ), b.end() );
    REP(i,b.size()){
    	if (i) num[b[i]]+=num[b[i-1]], sum[b[i]]+=sum[b[i-1]];
    	// debug(b[i]);
    	// debug(sum[b[i]]);
    }
    int idx = n-1;
    int btake = 0;
    int bmn = bs(m);
    int mx = cm * (bmn);
    if (bmn == A) mx += cf * n;
    int nmx = 0;

    while(idx>=0&&((m-(A-a[idx]))>=0)){
    	// debug(m);
    	m-=(A-a[idx]); nmx++;
    	num[a[idx]]--; sum[a[idx]]-=a[idx];
    	border = a[idx];
    	idx--;
    	int MN = bs(m);
    	int ans = (cf * nmx) + cm * (MN);
    	if (ans> mx) {
    		mx = ans; btake = nmx; bmn = MN; 
    	}
    }
    cout<<mx<<endl;
    // debug(btake);
    REP(i,btake){
    	orig[tmp[i].s]=A;
    }
    REP(i,n){
    	if (orig[i]<bmn) orig[i]=bmn;
    	cout<<orig[i]<<' ';
    }
}