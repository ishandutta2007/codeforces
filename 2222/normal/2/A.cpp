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

map<string,int> F;
vector< pair<string,int> > A;

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	int n;
	cin>>n;
	REP(i,n){
		char t[256]; int x;
		scanf("%s%d",t,&x);
		A.pb(make_pair(t,x));
		F[t]+=x;
	}
	set<string> R; int m=0;
	for(map<string,int>::iterator i=F.begin();i!=F.end();++i){
		if(i->Y>m)m=i->Y,R.clear();
		if(i->Y==m)R.insert(i->X);
	}
	F.clear();
	REP(i,sz(A))
		if(R.count(A[i].X)){
			if((F[A[i].X]+=A[i].Y)>=m){
				cout<<A[i].X<<endl;
				return 0;
			}
		}
	return 0;
}