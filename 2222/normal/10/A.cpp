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

int n,p1,p2,p3,t1,t2;
int l[111],r[111];

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin>>n>>p1>>p2>>p3>>t1>>t2;
	REP(i,n)cin>>l[i]>>r[i];
	int res=0;
	FOR(i,l[0],r[n-1]){
		int last=0;
		REP(j,n){
			if(l[j]>i)break;
			last=max(last,r[j]);
		}
		last=max(i-last,0);
		if(last<t1)res+=p1;
		else if(last<t1+t2)res+=p2;
		else res+=p3;
	}
	cout<<res<<endl;
	return 0;
}