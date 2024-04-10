// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+123,inf=1e8,mod=1e9+7,block=200,N=2053;
ll n,m,x,y,vx,vy;
ll phi (ll n) {
	ll result = n;
	for (ll i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}
ll binpow ( ll n, ll p,ll mod) {
	if (p == 0)
		return 1;
	ll c=binpow(n,p/2,mod);
	c=c*c%mod;
	if(p%2)            
		return c*n%mod;
	return c;
}
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
//	#else
//		freopen ("jumper.in", "r", stdin);
//		freopen ("jumper.out", "w", stdout);
	#endif     
	cin>>n>>m>>x>>y>>vx>>vy;
	if(vx==0){
		if(vy==1 && ( x==n  || x==0 ) )
			cout<<x<<" "<<m;
        else
        if(vy==-1 && ( x==n  || x==0 ) )
			cout<<x<<" "<<0;
		else
			cout<<-1;
		return 0;	
	}
    if(vy==0){
		if(vx==1 && ( y==m  || y==0 ) )
			cout<<n<<" "<<y;
        else
        if(vx==-1 && ( y==m  || y==0 ) )
			cout<<0<<" "<<y;
		else
			cout<<-1;
		return 0;	
	}
//  vx*k%n==(n-x)%n
    ll qx,qy,q,k,timer;
    if(vx==1)
    	qx=(n-x)%n;
  	else
  		qx=x%n;
    if(vy==1)
    	qy=(m-y)%m;
  	else
  		qy=y%m;
    // (n*x+qx)%m==qy   n*x%m=qy-qx
    q=( (qy-qx)%m+m )%m;
    if( q%__gcd(n,m)!=0 )
    	return cout<<-1,0;
    k= ( q/__gcd(n,m) ) * binpow( n/__gcd(n,m) , phi( m/__gcd(n,m) ) - 1 , m/__gcd(n,m) );
    k%=m/__gcd(n,m);
    timer=k*n+qx;
    //cout<<qx<<" "<<qy<<" "<<q<<" "<<k<<" "<<timer<<endl;
    
    // magic mod
    x=(x+timer*vx)%(2*n);
    y=(y+timer*vy)%(2*m);
    x=(x+2*n)%(2*n);
    y=(y+2*m)%(2*m);

    cout<<x<<" "<<y;
	/*
	 (vx*timer+x)%n==0  && (vy*timer+y)%m==0
	  vx*k%n==(n-x)%n
      vy*k%n==(n-y)%n
      vx=1 vy=1
      k%n==a k=n*x+a
      k%m==b (n*x+a)%m==b      new task a*x%mod=b   given a,mod,b find x
      							a*d%mod*d=b*d && a%mod=b     b%gcd(a,mod)==0 else -1
      						   new task a*x%mod=b gcd(a,mod)==1
      						   			x<mod x=b/a%mod   x=b*binpow(a,f(mod)-1)     
    */
}