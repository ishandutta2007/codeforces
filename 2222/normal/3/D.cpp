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
typedef pair<ll,int> pii;

const ll inf = 1000000000000ll;

ll a[55555],b[55555];
char s[55555];
int n;

inline int Z(char c){ return (c=='(')-(c==')'); }

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	scanf("%s",s);
	ll res=0;
	for(;s[n];++n){
		if(s[n]=='(') a[n]=0,b[n]=inf; else
		if(s[n]==')') a[n]=inf,b[n]=0; else
		{
			int x,y; scanf("%d%d",&x,&y);
			a[n]=x,b[n]=y;
		}
		if(a[n]<b[n])s[n]='(',res+=a[n];
		else s[n]=')',res+=b[n];
	}
	set<pii> S;
	int k=0;
	REP(i,n){
		k+=Z(s[i]);
		if(s[i]==')') S.insert(pii(a[i]-b[i],i));
		if(k<0){
			pii t=*S.begin();
			S.erase(S.begin());
			int j=t.Y;
			res-=b[j];
			res+=a[j];
			s[j]='(';
			k+=2;
		}
	}
	S.clear();
	k=0;
	for(int i=n-1;i>=0;--i){
		k-=Z(s[i]);
		if(s[i]=='(') S.insert(pii(b[i]-a[i],i));
		if(k<0){
			pii t=*S.begin();
			S.erase(S.begin());
			int j=t.Y;
			res-=a[j];
			res+=b[j];
			s[j]=')';
			k+=2;
		}
	}
	if(k==0 && res<inf){
		cout<<res<<endl;
		puts(s);
	}else puts("-1");
	return 0;
}