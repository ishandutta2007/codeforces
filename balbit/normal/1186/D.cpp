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

#define int ll

const int maxn = 1e5+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"NO"; exit(0);}

ll gcd(ll a, ll b){
	if (a%b==0) return b;
	return gcd(b, a%b);
}

bool can[maxn];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    int n;  cin>>n;
    int S = 0;
    vector<int> res(n);
    double S2 = 0;
    REP(i,n){
    	double d; cin>>d; S2+=d;
    	can[i]=1;
    	if (floor(d) == d){
    		res[i]=d; can[i]=0;
    	}else{
    		res[i]=floor(d);
    	}
    	S += res[i];
    }
    int i = 0;
    while (S<0) {
    	if (can[i]) {
    		res[i]++; S++;
    	}
    	i++;
    }
   	for (int x : res){
   		cout<<x<<'\n';
   	}
}