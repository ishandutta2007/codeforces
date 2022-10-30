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

string s,a,b;

vector<int> ss(const string &a, const string &s){
	vector<int> p(sz(a),-1),res;
	for(int i=0;i+sz(a)<=sz(s);++i){
		if(strncmp(a.data(),s.data()+i,sz(a))==0)
			res.push_back(i);
	}
	return res;
	int x = -1;
	for(int i=1;i<a.size();++i){
		for(;x>=0 && a[x+1]!=a[i];x=p[x]);
		if(a[x+1]==a[i])++x;
		p[i]=x;
	}
	for(int i=0;i<s.size();++i){
		for(;x>=0 && a[x+1]!=s[i];x=p[x]);
		if(a[x+1]==s[i])++x;
		if(x+1==sz(a))res.push_back(i-x);
	}
	return res;
}

bool check(){
	vector<int> A=ss(a,s),B=ss(b,s);
	if(sz(A)==0 || sz(B)==0) return false;
	return A[0]+sz(a)<=B.back();
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin>>s>>a>>b;
	bool f=check();
	reverse(all(s));
	bool b=check();
	if(f && b) puts("both");
	else if(f) puts("forward");
	else if(b) puts("backward");
	else puts("fantasy");	
	return 0;
}