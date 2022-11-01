#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	vector<string> a(1);
	int w = 0;
	for(string s; getline(cin, s); ) a.pb(s), w = max(w, sz(s));
	bool par=false;
	FOR(i,1,sz(a)){
		int k1=(w-sz(a[i]))/2,k2=(w+1-sz(a[i]))/2;
		if(k1!=k2){
			if(par)swap(k1,k2);
			par=!par;
		}
		a[i]="*"+string(k1,' ')+a[i]+string(k2,' ')+"*";
	}
	a[0]=string(w+2,'*');
	a.pb(a[0]);
	REP(i,sz(a))cout<<a[i]<<endl;
	return 0;
}