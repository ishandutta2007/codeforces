//Chandnani submission.            
#include <bits/stdc++.h>
            using namespace std;
             
             
            void __print(int x) {cerr << x;}
            void __print(long x) {cerr << x;}
            void __print(long long x) {cerr << x;}
            void __print(unsigned x) {cerr << x;}
            void __print(unsigned long x) {cerr << x;}
            void __print(unsigned long long x) {cerr << x;}
            void __print(float x) {cerr << x;}
            void __print(double x) {cerr << x;}
            void __print(long double x) {cerr << x;}
            void __print(char x) {cerr << '\'' << x << '\'';}
            void __print(const char *x) {cerr << '\"' << x << '\"';}
            void __print(const string &x) {cerr << '\"' << x << '\"';}
            void __print(bool x) {cerr << (x ? "true" : "false");}
             
            template<typename T, typename V>
            void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
            template<typename T>
            void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
            void _print() {cerr << "]\n";}
            template <typename T, typename... V>
            void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
            #ifndef ONLINE_JUDGE
            #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
            #else
            #define debug(x...)
            #endif
             
            #define rep(i, n)    for(int i = 0; i < (n); ++i)
            #define repA(i, a, n)  for(int i = a; i <= (n); ++i)
            #define repD(i, a, n)  for(int i = a; i >= (n); --i)
            #define trav(a, x) for(auto& a : x)
            #define all(x) x.begin(), x.end()
            #define sz(x) (int)(x).size()
            #define fill(a)  memset(a, 0, sizeof (a))
            #define fst first
            #define snd second
            #define mp make_pair
            #define pb push_back
            typedef long double ld;
            typedef long long ll;
            typedef pair<int, int> pii;
            typedef vector<int> vi;
             
            void pre(){
             
             
            }
            int n,m;
            int a[(1<<21)+9];
            int f[(1<<21)+9];
            void fx(int x){
            	if(a[2*x]==a[2*x+1]&&a[2*x]==0){
            		a[x] = 0;
            		return;
            	}
            	int bg = 2*x,sm=2*x+1;
            	if(a[2*x]<a[2*x+1]) swap(bg,sm);
            	a[x]=a[bg];
            	fx(bg);
            	bg = 2*x,sm=2*x+1;
            	if(a[2*x]<a[2*x+1]) swap(bg,sm);
            	if(a[2*x]==a[2*x+1]) {
            		if(x>m) f[x]=x;
            		else f[x]=0;
            	}
            	else if(f[bg]==bg) f[x]=x;
            	else if(a[f[bg]]>a[f[sm]]) f[x]=f[bg];
            	else f[x]=f[sm];
            }
            vi ans;
            void solve(){
            	int h,g;cin>>h>>g;
            	n=(1<<h)-1;
            	m=(1<<g)-1;
            	repA(i,1,n) cin>>a[i],a[i+n]=0;
            	repA(i,1,n) f[i]=i,f[i+n]=0;
                a[2*n+1]=f[2*n+1]=0;
                    ans.clear();
                ans.reserve(n-m);
            	rep(i,n-m){
            		int x = f[1];
            		ans.pb(f[1]);
            		fx(f[1]);
            		x/=2;
            		while(x>=1){
            			int bg = 2*x,sm=2*x+1;
            			if(a[2*x]<a[2*x+1]) swap(bg,sm);
            			if(a[2*x]==a[2*x+1]) {
            				if(x>m) f[x]=x;
            				else f[x]=0;
            			}
            			else if(f[bg]==bg) f[x]=x;
            			else if(a[f[bg]]>a[f[sm]]) f[x]=f[bg];
            			else f[x]=f[sm];
            			x/=2;	
            		}
            	}
            	ll sum = 0;
            	repA(i,1,m) sum+=a[i];
            	cout<<sum<<'\n';
            	trav(i,ans) cout<<i<<' ';
            	cout<<'\n';
            }
             
            int main() {
            	cin.sync_with_stdio(0); cin.tie(0);
            	cin.exceptions(cin.failbit);
            	pre();
            	int n;cin>>n;
            	rep(i,n) solve();
            	return 0;
            }