#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <limits>
#include<cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <ios>

using namespace std;

#define tr(c, it)  for(typeof(c.begin()) it=c.begin();  it != c.end(); it++)
#define tr11(c, it)  for(auto it=c.begin();  it != c.end(); it++)
#define RF(i,x,st) for(int i=x-1;i>=st;i--)
#define F(i,x,st) for(int i=st;i<x;i++)
#define Fb(i,b,st) for(int i=st;b;i++)
#define rall(c) c.rbegin(),c.rend()
#define all(c) c.begin(),c.end()
#define p(i,j) pair< i , j >
#define INF 1000000000000ll
#define SP system("pause")
#define v(i) vector< i >
#define d(i) deque< i >
#define ld long double
#define int long long
#define pf push_front
#define mp make_pair
#define pb push_back
#define sz size

/* input */
 template<typename T>istream& operator >> ( std::istream& in,v(T)&a){tr11(a,it)in>>*it;}
 template<typename T1,typename T2>istream& operator >>( std::istream& in,p(T1,T2)&a){in>>a.first>>a.second;}
 
/* output */
 template<typename T>ostream& operator << ( std::ostream& out,v(T)&a){tr11(a,it){out<<*it;out<<endl;}}
 template<typename T>ostream& operator << ( std::ostream& out,set<T>&a){tr11(a,it){out<<*it;out<<endl;}}
 
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,p(T1,T2)&a){out<<a.first<<' '<<a.second;}
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,map<T1,T2>&a){tr11(a,it){out<<*it;out<<endl;}}


#define ONLINE_JUDGE

 main()
 { 
#ifndef ONLINE_JUDGE
 freopen("input.txt","rt",stdin);
 freopen("output.txt","wt",stdout);
#endif
  string s;
  cin>>s;
  int need[3]={0};
  for(int i=0;i<s.size();i++)
  {
	if(s[i]=='B')		
	need[0]++;
	if(s[i]=='S')
	need[1]++;
	if(s[i]=='C')
	need[2]++;
  }
  
  int have[3];
  cin>>have[0]>>have[1]>>have[2];
  
  int cost[3];
  cin>>cost[0]>>cost[1]>>cost[2];
  
  int r;
  cin>>r;
  
  int l=0,R=1e13;
  while(l<R)
  {
	int m=l+max(1ll,(R-l)/2);
	
	int cur=0;
	cur+=max(0ll,cost[0]*(m*(need[0])-have[0]));
	cur+=max(0ll,cost[1]*(m*(need[1])-have[1]));
	cur+=max(0ll,cost[2]*(m*(need[2])-have[2]));
	if(cur<=r)
	l=m;
	else
	R=m-1;
  }
  cout<<l<<endl;
 }