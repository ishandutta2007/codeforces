#pragma GCC optimize("Ofast")   //Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  randomINIT     mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define  foo(i,a,n)     for(ll i = (a); i <= n; i++)
#define  frr(i,a,n)     for(ll i = (a); i >= n; i--)
#define  fo(i,n)        for(ll i = 0; i < n; i++)
#define  all(x)         (x).begin(),(x).end()
#define  mset(x,val)    memset(x,val,sizeof(x))
#define  newl           cout<<"\n"
#define  pb             push_back
#define  mp             make_pair
#define  s              second
#define  f              first
#define  dline          cerr<<"///REACHED///\n";
#define  deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define  deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define  deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   MAXN  =  1e+5+7;

vll adj[MAXN];ll visit[MAXN]={};
int dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1};
int dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

//<<-----Declare Variable Here------->>//
int t=1;
ll n,k,d1,d2;
ll max1,min1;
ll flag1,flag2,flag3,flag4;
ll t1,t2,t3;
//<<-----Implement Functions Here---->>//


//<<-----Start of Main--------------->>//
void MAIN(){
		cin>>n>>k>>d1>>d2;ll d = n-k;
		flag1 = 0,flag2 = 0,flag3 = 0,flag4 = 0;
		//case1
		t2 = d2;t1 =d1+d2;t3 = 0;
		if(t1+t2+t3<=k)
		{
			ll dh = k-(t1+t2+t3);ll dq = d-(2*d1+d2);
			if(dh%3==0){t1+=dh/3;t2+=dh/3;t3+=dh/3;}else flag1 =1;
			if(d>=2*d1+d2){t2=t1;t3=t1;}else flag1 = 1;
			if(dq%3!=0)flag1 = 1;
		}else flag1 = 1;
		//case2
		t1 = d1;t3 = d2;t2 = 0;
		if(t1+t2+t3<=k)
		{
			ll dh = k-(t1+t2+t3);max1 = max(d1,d2);min1 = min(d1,d2);
			ll dq = d - (2*max1-min1);
			if(dh%3==0){t1+=dh/3;t2+=dh/3;t3+=dh/3;}else flag2 =1;
			if(d>=2*max1-min1){if(d1>d2){t2 = t1;t3 = t1;}else {t1 = t3;t2 = t3;}}
			else flag2 = 1;

			if(dq%3!=0)flag2 = 1;
		}else flag2 = 1;
		//case3
		t2 = max(d1,d2);if(d1>d2){t1 =0;t3=d1-d2;}else{t3 =0;t1=d2-d1;}
		if(t1+t2+t3<=k)
		{
			ll dh = k-(t1+t2+t3);ll dq = d-(d1+d2);
			if(dh%3==0){t1+=dh/3;t2+=dh/3;t3+=dh/3;}else flag3 =1;
			if(d>=d1+d2){t1 = t2;t3 = t2;}else flag3 = 1;
			if(dq%3!=0)flag3 = 1;
		}else flag3 = 1;
		//case 4
		t3 = d1+d2;t2 = d1;t1 = 0;
		if(t1+t2+t3<=k)
		{
			ll dh = k-(t1+t2+t3);ll dq = d-(2*d2+d1);
			if(dh%3==0){t1+=dh/3;t2+=dh/3;t3+=dh/3;}else flag4 =1;
			if(d>=2*d2+d1){t2=t3;t1=t3;}else flag4 = 1;
			if(dq%3!=0)flag4 = 1;
		}else flag4 = 1;
		//cout<<flag1<<flag2<<flag3<<flag4<<" ";
		if(!flag1||!flag2||!flag3||!flag4)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
}

int main(){
	fastio;randomINIT;

	cin>>t;
	while(t--){
		MAIN();
	}

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}