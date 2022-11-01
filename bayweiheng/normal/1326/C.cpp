#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef tuple<int,int,int> iii;

#define pb push_back
#define ctz __builtin_ctz
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

const ll mod=998244353;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    ll ans1=0,ans2=1;
    cin>>n>>k;
    int lo=n-k+1;
    for(int i=lo;i<=n;++i) {
    	ans1+=i;
    }
    int a[n],prev=-1;
    rep(i,n) {
    	cin>>a[i];
    	if(a[i]>=lo) {
    		if(prev!=-1) {
    			ans2=(ans2*(i-prev)) % mod;
    		}
    		prev=i;
    	}
    }
    printf("%lld %lld\n",ans1,ans2);



}