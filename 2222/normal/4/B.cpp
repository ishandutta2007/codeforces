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

int n,s;
int a[33],b[33];
int F[33][333];

vi R;

int f(int i,int s){
	if(i==n) return s==0;
	if(s<0) return 0;
	int&res=F[i][s];
	if(res<0){
		res=0;
		for(int j=a[i];j<=b[i];++j)
			if(f(i+1,s-j)){
				R.pb(j);
				return res=1;
			}
	}
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	CL(F,-1);
	cin>>n>>s;
	REP(i,n)cin>>a[i]>>b[i];
	if(f(0,s)){
		puts("YES");
		reverse(all(R));
		REP(i,sz(R)){
			if(i)putchar(' ');
			printf("%d",R[i]);
		}
		puts("");
	}else puts("NO");
	return 0;
}