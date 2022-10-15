#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast", "unroll-loops")
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

// #define int ll

const int maxn = 1005;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"NO"; exit(0);}

ll gcd(ll a, ll b){
	if (a%b==0) return b;
	return gcd(b, a%b);
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string a, b; cin>>a>>b;
    int n = a.length(), m = b.length();
    vector<int> ps (n);
    
    {
    	REP(i,n-1){
    		ps [1+i] = ps[i];
    		ps[i+1]+= (a[i]!=a[i+1]);
    	}
    }

    int sum = 0;
    int re = 0;
    {
    	REP(i,m){
    		if (a[i]!=b[i]) sum++;
    	}
    }
    if (sum%2==0) re++;
    {
    	FOR(i, m-1, n-1){
    		// cout<<"TRY"<<endl;
    		if ((ps[i+1]-ps[i-m+1])%2==1){
    			sum++;
    		}
    		if (sum%2==0) re++;
    	}
    }
    cout<<re<<endl;


}