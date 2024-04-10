#pragma comment(linker,"/STACK:228000000")
#include <vector>
#include <string.h>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <limits>
#include <complex>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornr(i,n) for(int i=(n)-1;i>=0;--i)
#define forv(i,v) forn(i,(int)v.size())
#define time asdtime
#define pb push_back
#define lng long long
#define mp make_pair
#define iinf 1000000000
#define prev asdprev
#define next asdnext
#define all(v) v.begin(),v.end()
#define SQ(a) ((a)*(a))
#define eps 1e-8
#define y1 asdy1
#define y2 asdy2
#define ABS(a) ((a)<0?-(a):(a))
#define PI 3.1415926535897932384626433832795

bool have[26];

int main(int argc,char **argv){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	
	int k;
	string s0;
	cin>>k>>s0;
	int n=(s0.length()+1)/2;
	string s;
	int holes=0;
	forn(i,n){
		s+='?';
		char a,b;
		a=s0[i];
		b=s0[s0.length()-1-i];
		if(a=='?')
			s[i]=b;
		else if(b=='?')
			s[i]=a;
		else if(a==b)
			s[i]=a;
		else{
			cout<<"IMPOSSIBLE";
			return 0;
		}
		if(s[i]!='?')
			have[s[i]-'a']=true;
		else
			++holes;
	}
	string unhave;
	forn(i,k)
		if(!have[i])
			unhave+=(char)('a'+i);
	if(holes<unhave.length()){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	reverse(all(unhave));
	forn(i,s.length()){
		if(s[i]!='?')
			continue;
		if(holes>unhave.length())
			s[i]='a';
		else{
			s[i]=unhave[unhave.length()-1];
			unhave.erase(unhave.end()-1);
		}
		--holes;
	}
	cout<<s;
	if(s0.length()%2)
		s.erase(s.end()-1);
	reverse(all(s));
	cout<<s;

	return 0;
}