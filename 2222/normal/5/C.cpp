#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
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

char s[1<<20];

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	gets(s);
	int n=0,k=0;
	ll res=1;
	stack<pii> S;
	S.push(pii(0,-1));
	for(int i=0;s[i];++i){
		int x=(s[i]=='(')-(s[i]==')');
		k+=x;
		for(;S.size() && S.top().X>k;S.pop());
		if(S.size()){
			if(S.top().X==k){
				int len=i-S.top().Y;
				if(len>n)n=len,res=1;
				else if(len==n)++res;
			}else S.push(pii(k,i));
		}else S.push(pii(k,i));
	}
	cout<<n<<' '<<res<<endl;
	return 0;
}