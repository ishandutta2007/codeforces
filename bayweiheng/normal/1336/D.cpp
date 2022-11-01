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
#define pct __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

int triangle[102];
const int maxn=105;
int dt[maxn],ds[maxn];
int t,s,nt,ns;

void query(int i,int idx) {
   	cout<<"+ "<<i<<endl;
   	cin>>nt>>ns;
   	dt[idx]=nt-t; ds[idx]=ns-s;
   	t=nt;s=ns;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cin>>t>>s;
    rep(i,102) {
    	triangle[i]=i*(i-1)/2;
    }
   	vi ans(n+1,-1);
   	query(1,1);
   	query(2,2);
   	query(3,3);
   	query(1,n);
   	for(int i=4;i<n;++i) { // n-4
   		query(i,i);
   	}
    rep(i,n-1) {
    	if(dt[i+1]>0) {
    		db2(i+1,dt[i+1]);
    		ans[i+1]=lower_bound(triangle,triangle+102,dt[i+1])-triangle;
    	}
    }
    if(ans[1]==-1) {
    	ans[1]=dt[n]==1 ? 1 : 0;
    }
    if(ds[1]==0) { // a2 * a3 = 0
    	if(ds[2]==0) {
    		ans[3]=0;
    	} else {
    		ans[2]=0;
    		if(ans[3]==-1) ans[3]=1;
    	}
    } else {
    	if(ans[3]==-1) ans[3]=1;
    }
    if(ans[2]==-1) {
    	ans[2] = ds[n] / (ans[3]+1) - 1;
    }
    for(int i=3;i<n-1;++i) {
    	if(ans[i+1]==-1) {
    		int o = ds[i] - (ans[i-1]+1) * (ans[i-2]+1);
    		ans[i+1] = o==0 ? 0 : 1;
    	}
    }
   	// finally do n
   	ans[n] = ds[n-1] / (ans[n-2]+1) - (ans[n-3]+1);
    cout<<"!";
    rep(i,n) cout<<" "<<ans[i+1];
    cout<<endl;




}