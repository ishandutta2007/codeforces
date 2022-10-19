#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("trapv")
#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
#define rsz(x) resize(x)

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=3e5+5, K=18, mod=998244353, INF=1e9+5;
int n;
ll quer(ll l, ll r){
	cout<<"? "<<l<<" "<<r<<endl;
	ll k=0;
	cin>>k;
	/*ll d1=r-max(l, 4)+1;
	if(d>0)k=d*(d-1)/2;
	if(l<=2 && r>=3)k++;
	cout<<k<<endl;*/
	return k;
}
int main(){
	//BOOST;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ll l=1, r=n;
		ll k;
		ll cnt=0;
		k=quer(1, n);
		//cout<<"? "<<1<<" "<<n<<endl;
		cnt++;
		ll pocz, kon;
		while(l<r){
			ll m=(l+r)>>1;
			ll k1;
			assert(cnt<40);
			cnt++;
			k1=quer(l, m);
			if(k1!=k && k1!=0){
				cerr<<"q"<<endl;
				ll k2;
				cnt++;
				k2=quer(m+1, r);
				ll l1=sqrt(8*k1+1), l2=sqrt(8*k2+1);
				l1=(l1+1)/2;
				l2=(l2+1)/2;
				deb(l1, l2);
				if(l1*(l1-1)==2*k1 && m>=l1){
					cerr<<"a"<<endl;
					ll a;
					assert(cnt<40);
					//cout<<"? "<<m-l1+1<<" "<<m<<endl;
					cnt++;
					a=quer(m-l1+1, m);
					if(2*a==(l1-1)*(l1)){
						cerr<<"b"<<endl;
						pocz=m-l1+1;
						l=m;
						while(l<r){
							m=(l+r)>>1;
					assert(cnt<40);

							//cout<<"? "<<pocz<<" "<<m<<endl;
							cnt++;
							k1=quer(pocz, m);
							if(k1==k)r=m;
							else{
								l=m+1;
							}
						}
						kon=l;
						break;
					}
				}
				cerr<<"c"<<endl;
				kon=m+l2;
				r=m;
				while(l<r){
					m=(l+r+1)>>1;
					assert(cnt<40);

						//cout<<"? "<<m<<" "<<kon<<endl;
						cnt++;
						k1=quer(m, kon);
						if(k1==k)l=m;
						else{
							r=m-1;
						}
					}
					pocz=l;
					break;
			}
			else if(r==l+1){
				pocz=l;
				kon=r;
			}
			if(k1==0){
				l=m;
			}
			else{
				r=m;
			}
		}
		ll d=kon-pocz+1;
		ll s=d-sqrt(d*d-2*d*(d-1)+4*k);
		s/=2;
		assert(cnt<40);
		//cout<<"? "<<kon-s<<" "<<kon<<endl;
		cnt++;
		//deb(cnt);
		k=quer(kon-s, kon);
		if(2*k==s*(s+1))cout<<"! "<<pocz<<" "<<pocz+s<<" "<<kon<<endl;
		else cout<<"! "<<pocz<<" "<<pocz+d-s<<" "<<kon<<endl;
	}
}