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

char s[5555555];
int f[5555555];

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	gets(s);
	f[0]=1;
	long long h1=s[0],h2=s[0],d=1;
	int res=1;
	for(int i=1;s[i];++i){
		d*=37;
		h1+=s[i]*d;
		h2=h2*37+s[i];
		if(h1==h2)f[i]=f[(i+1)/2-1]+1;
		res+=f[i];
	}
	cout<<res<<endl;
	return 0;
}