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

typedef long long unsigned int llui;
typedef long long int lli;
typedef long double float64;

llui mul_mod(llui a, llui b, llui m){
   llui y = (llui)((float64)a*(float64)b/m+(float64)1/2);
   y = y * m;
   llui x = a * b;
   llui r = x - y;
   if ( (lli)r < 0 ){
      r = r + m; y = y - 1;
   }
   return r;
}

llui C,a,b;

ll gcd(ll a,ll b) {
	return a%b==0 ? b : gcd(b,a%b);
}

llui gcd(){
   llui c;
   if(a>b){
      c = a; a = b; b = c;
   }
   while(1){
      if(a == 1LL) return 1LL;
      if(a == 0 || a == b) return b;
      c = a; a = b%a;
      b = c;
   }
}

llui f(llui a, llui b){
   llui tmp;
   tmp = mul_mod(a,a,b);
   tmp+=C; tmp%=b;
   return tmp;
}

llui pollard(llui n){
   if(!(n&1)) return 2;
   C=0;
   llui iteracoes = 0;
   while(iteracoes <= 1000){
      llui x,y,d;
      x = y = 2; d = 1;
      while(d == 1){
          x = f(x,n);
          y = f(f(y,n),n);
          llui m = (x>y)?(x-y):(y-x);
          a = m; b = n; d = gcd();
      }
      if(d != n)
          return d;
      iteracoes++; C = rand();
   }
   return 1;
}

llui pot(llui a, llui b, llui c){
   if(b == 0) return 1;
   if(b == 1) return a%c;
   llui resp = pot(a,b>>1,c);
   resp = mul_mod(resp,resp,c);
   if(b&1)
      resp = mul_mod(resp,a,c);
   return resp;
}

// Rabin-Miller primality testing algorithm
bool isPrime(llui n){
   llui d = n-1;
   llui s = 0;
   if(n <=3 || n == 5) return true;
   if(!(n&1)) return false;
   while(!(d&1)){ s++; d>>=1; }
   for(llui i = 0;i<32;i++){
      llui a = rand();
      a <<=32;
      a+=rand();
      a%=(n-3); a+=2;
      llui x = pot(a,d,n);
      if(x == 1 || x == n-1) continue;
      for(llui j = 1;j<= s-1;j++){
         x = mul_mod(x,x,n);
         if(x == 1) return false;
         if(x == n-1)break;
      }
      if(x != n-1) return false;
   }
   return true;
}
map<llui,int> factors;
// Precondition: factors is an empty map, n is a positive integer
// Postcondition: factors[p] is the exponent of p in prime factorization of n
void fact(llui n){
   if(!isPrime(n)){
      llui fac = pollard(n);
      fact(n/fac); fact(fac);
   }else{
      map<llui,int>::iterator it;
      it = factors.find(n);
      if(it != factors.end()){
         (*it).second++;
      }else{
         factors[n] = 1;
      }
   }
}

const ll md=998244353;
const int maxn=60;
ll ft[maxn],invft[maxn];

ll powmod(ll base,ll expo) {
	ll a=base,ans=1;
	while(expo) {
		if(expo&1) ans=(ans*a)%md;
		expo/=2;
		a=(a*a)%md;
	}
	return ans;
}
unordered_map<ll,ll> mp;

ll f(ll a) {
	if(mp.count(a)) return mp[a];
	factors.clear();
	fact(a);
	ll ans=1;
	int sum=0,c;
	for(auto &p:factors) {
		c=p.second;
		sum+=c;
		ans=(ans*invft[c])%md;
	}
	ans=(ans*ft[sum])%md;
	return mp[a]=ans;
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ft[0]=invft[0]=1;
    rep(i,maxn) {
    	if(i==0) continue;
    	ft[i]=(ft[i-1]*i)%md;
    	invft[i]=powmod(ft[i],md-2);
    }
    ll d;
    int q;
    cin>>d>>q;
    ll u,v;
    while(q--) {
    	cin>>u>>v;
    	ll d=gcd(u,v);
    	u/=d;
    	v/=d;
    	ll ans=(f(u)*f(v))%md;
    	cout<<ans<<endl;
    }

}