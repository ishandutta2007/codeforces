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

int gcd(int a,int b)
{return b?gcd(b,a%b):a;}

 main()
 { 
#ifndef ONLINE_JUDGE
 freopen("input.txt","rt",stdin);
 freopen("output.txt","wt",stdout);
#endif
  int a,b;
  cin>>a>>b;
  int GCD=gcd(a,b);
  int c=a/GCD;
  int d=b/GCD;
  
  int count1=0;
  int count2=0;
  while(!(c%2))
  count1++,c/=2;
  while(!(c%3))
  count1++,c/=3;
  while(!(c%5))
  count1++,c/=5;
  while(!(d%2))
  count2++,d/=2;
  while(!(d%3))
  count2++,d/=3;
  while(!(d%5))
  count2++,d/=5;
  if(c!=1 || d!=1)
  cout<<-1<<endl;
  else
  cout<<count1+count2<<endl;
 }