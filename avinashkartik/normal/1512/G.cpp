#pragma GCC optimize("Ofast")   //Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  randomINIT     mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define  all(x)         (x).begin(),(x).end()
#define  mset(x,val)    memset(x,val,sizeof(x))
#define  endl           "\n"
#define  pb             push_back
#define  sym(s)         s="#"+s+"#";
#define  mp             make_pair
#define  s              second
#define  f              first
#define  dline          cerr<<"///REACHED///\n";
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());

typedef  long long             ll;
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   N  =  1e7+5;

vll adj[N];ll vis[N]={};
int dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1};
int dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

//<<-----Declare Variable Here------->>//
int t=1;
ll n,c;
ll ans[N+5];
ll ans1[N+10];
//<<-----Implement Functions Here---->>//


//<<-----Start of Main--------------->>//
void MAIN(){
		cin>>c;
		if(ans1[c])cout<<ans1[c]<<endl;
		else cout<<-1<<endl;
}

int main(){
    fastio;randomINIT;
    for(ll i=1;i<=N;i++){
		for(ll j=i;j<=N;j+=i)ans[j] += i;
	}
	for(ll i=1;i<=N;i++){
	    if(ans[i]>1e7) continue;
		if(ans1[ans[i]] == 0){
			ans1[ans[i]] = i;
		}
	}
		
	// for(ll i=1;i<=N;i++)cout<<ans[i]<<" ";

    cin>>t;
    while(t--){
        MAIN();
    }

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}