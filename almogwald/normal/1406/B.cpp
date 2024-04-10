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
typedef long long lol;
#define into(b) cin >> b;
#define def(b) lol b; into(b)
#define co cout <<
#define con continue;
#define el << endl;
#define ex return 0;
#define all(arr) arr.begin(), arr.end()
typedef vector<int> veci;


int main() {
	def(t)
	fori(kkk,t){
		def(n)
		veci plus;
		veci minus;
		fori(i,n){
			def(a)
			if(a<0){
				minus.push_back(-a);
			}else{
				plus.push_back(a);
			}
		}
		sort(all(plus));
		sort(all(minus));
		lol ans = -999999999999999999;
		if(plus.size()>4){
			lol curans=1;
			fort(i,plus.size()-5,plus.size()){
				curans *= plus[i];
			}
			ans=max(ans,curans);
		}
		if(plus.size()>2 && minus.size()>1){
			lol curans=1;
			fort(i,plus.size()-3,plus.size()){
				curans *= plus[i];
			}
			fort(i,minus.size()-2,minus.size()){
				curans *= minus[i];
			}
			ans=max(ans,curans);
		}
		if(plus.size()>0 && minus.size()>3){
			lol curans=1;
			fort(i,plus.size()-1,plus.size()){
				curans *= plus[i];
			}
			fort(i,minus.size()-4,minus.size()){
				curans *= minus[i];
			}
			ans=max(ans,curans);
		}
		if(minus.size()>4){
			lol curans=-1;
			fori(i,0){
				curans *= plus[i];
			}
			fori(i,5){
				curans *= minus[i];
			}
			ans=max(ans,curans);
		}
		if(plus.size()>1 && minus.size()>2){
			lol curans=-1;
			fori(i,2){
				curans *= plus[i];
			}
			fori(i,3){
				curans *= minus[i];
			}
			ans=max(ans,curans);
		}
		if(plus.size()>3 && minus.size()>0){
			lol curans=-1;
			fori(i,4){
				curans *= plus[i];
			}
			fori(i,1){
				curans *= minus[i];
			}
			ans=max(ans,curans);
		}
		co ans el
	}
	return 0;
}