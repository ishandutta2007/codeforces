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

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--) {
    	int n;
    	cin>>n;
    	int a[n];
    	int pcnt[n][200];
    	vi pos[200];
    	rep(i,n) {
    		cin>>a[i];
    		--a[i];
    	}
    	rep(i,n) {
    		if(i==0) {
	    		rep(j,200) {
	    			pcnt[i][j]=a[i]==j;
	    		}
	    	} else {
	    		rep(j,200) {
	    			pcnt[i][j]=pcnt[i-1][j]+(a[i]==j);
	    		}
	    	}
	    	pos[a[i]].pb(i);
    	}
    	int ans=0;
    	int cnt[200];
    	rep(j,200) {
    		cnt[j]=pcnt[n-1][j];
    		ans=max(ans,cnt[j]);
    	}
    	rep(j,200) {
    		int l=pos[j].size();
    		rep(i,l/2) {
    			int base=2*(i+1);
    			int li=pos[j][i],ri=pos[j][l-1-i];
    			//db2(j,i);
    			//db2(li,ri);
    			// query i+1, r-1
    			if(li+1>ri-1) ans=max(ans,base);
    			else {
    				int t=0;
    				rep(k,200) {
    					t=max(pcnt[ri-1][k]-pcnt[li][k],t);
    				}
    				//db(t);
    				//if(t==1) db2(pcnt[5][1],pcnt[2][1]);
    				ans=max(ans,base+t);
    			}
    		}
    	}
    	cout<<ans<<endl;
    }

}