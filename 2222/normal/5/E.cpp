#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <stack>
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

int n;
int a[1<<21],*x=a;

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	srand(time(0));
	#endif
	cin>>n;
	int f[]={0,0,0};
	REP(i,n){
		scanf("%d",a+i);
		a[i+n]=a[i];
		f[0]=a[i];
		sort(f,f+3);
		if(a[i]>*x)x=a+i;
	}
	ll res=0;
	++x;
	REP(k,2){
		stack<pii> S;
		REP(i,n){
			for(;S.size();)
				if(x[S.top().X]<x[i])S.pop(),++res;
				else break;
			if(S.size() && x[S.top().X]==x[i] && k)
				res+=S.top().Y, S.push(pii(i,S.top().Y+1));
			else S.push(pii(i,1));
		}
		reverse(x,x+n-1);
	}
	if(count(x,x+n,f[2])==1)res-=count(x,x+n,f[1]);
	cout<<res<<endl;
	return 0;
}