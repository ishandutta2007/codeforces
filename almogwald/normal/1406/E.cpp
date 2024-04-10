#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
#define fort(i,a,b) for(int i=a;i<b;i++)
#define fori(i,b) fort(i,0,b)
#define forn(i,b) fort(i,1,b)
#define forin(i,b) fori(i,b.size())
#define fortb(i,a,b) for(int i=b-1;i>=a;i--)
#define forib(i,b) fortb(i,0,b)
#define fornb(i,b) fortb(i,1,b)
typedef long long lol;
#define into(b) cin >> b;
#define def(b) lol b; into(b)
#define co cout <<
#define con continue;
#define br break;
#define el << endl;
#define ell << '\n';
#define ex return 0;
#define all(arr) arr.begin(), arr.end()
typedef vector<lol> veci;

int main() {
	ios::sync_with_stdio(0);
	def(n)
	if(n==1){
		co 'C' << ' ' << n el
				ex
	}
	veci a(n+1,1);
	veci b(n+1,1);
	veci sum(n+1);
	veci p;
	fort(i,2,n+1){
		if(a[i]){
			p.push_back(i);
			for(int j=i;j<=n;j+=i){
				sum[i]+=a[j];
				a[j]=0;
			}
		}
	}
	int cur=1;
	/*int low=p.size();
	int count=n;
	while(low>0){
		int mid=low/2;
		fort(i,mid,low){
			co 'B' << ' ' << p[i] el
					def(x)
			count-=x;
		}
		co 'A' << ' ' << 1 el
			def(x)
		if(x>count){
			fort(i,mid,low){
				int pp=p[i];
				co 'A' << ' ' << pp el
				def(x)
				while(x){
					cur*=p[i];
					pp*=p[i];
					if(pp>n){
						br
					}
					co 'A' << ' ' << pp el
						into(x)
				}
			}
			mid=min(mid,200);
			fori(i,mid){
				int pp=p[i];
				co 'A' << ' ' << pp el
				def(x)
				while(x){
					cur*=p[i];
					pp*=p[i];
					if(pp>n){
						br
					}
					co 'A' << ' ' << pp el
						into(x)
				}
			}
			br
		}else{
			low=mid;
		}

	}*/
	int low=0;
		int count=n;
	while(low<p.size()){
			int mid=(low+p.size()+1)/2;
			if(low==0){
				mid=min(mid,100);
			}
			fort(i,low,mid){
				//count-=sum[p[i]];
				co 'B' << ' ' << p[i] el
						def(x)
				for(int j=p[i];j<=n;j+=p[i]){
					b[j]=0;
				}
				count-=x;
			}
			co 'A' << ' ' << 1 el
				def(x)
			if(x>count){
				if(low==0){
					mid=p.size();
				}
				fort(i,low,mid){
					lol pp=p[i];

					co 'A' << ' ' << pp el
					def(x)
					int supposed=0;
					for(int j=pp;j<=n;j+=pp){
						supposed+=b[j];
					}
					while(x>supposed){
						cur*=p[i];
						pp*=p[i];
						if(pp>n){
							br
						}
						co 'A' << ' ' << pp el
						supposed=0;
						for(int j=pp;j<=n;j+=pp){
							supposed+=b[j];
						}
							into(x)
					}
				}
				br
			}else{
				low=mid;
			}

		}
	co 'C' << ' ' << cur el
		ex
	return 0;
}