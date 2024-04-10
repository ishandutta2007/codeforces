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

ll A, B, C;

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin >> A >> B >> C;
	ll Ax=1,Bx=0,Ay=0,By=1;
	for(;B;swap(A,B),swap(Ax,Bx),swap(Ay,By)){
		ll k=A/B;
		A-=B*k;
		Ax-=Bx*k;
		Ay-=By*k;
	}
	if (C % A) puts("-1");
	else {
		Ax*=-C/A,Ay*=-C/A;
		if(abs(Ax)<=5000000000000000000ll && abs(Ay)<=5000000000000000000ll)
			cout<<Ax<< ' '<<Ay<<endl;	
		else puts("-1");
	}
	return 0;
}