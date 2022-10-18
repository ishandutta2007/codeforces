#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <limits>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <ios>
 
using namespace std;
 
#define tr(c, it)  for(typeof(c.begin()) it=c.begin();  it != c.end(); it++)
#define RF(i,x,st) for(int i=x-1;i>=st;i--)
#define F(i,x,st) for(int i=st;i<x;i++)
#define Fb(i,b,st) for(int i=st;b;i++)
#define rall(c) c.rbegin(),c.rend()
#define all(c) c.begin(),c.end()
#define SP system("PAUSE")
#define p(i,j) pair< i , j >
#define ld long double
#define v(i) vector< i >
#define d(i) deque< i >
#define int long long
#define mp make_pair
#define pb push_back
#define pf push_front

template<typename T>inline void read_arr(T&a){F(i,a.size(),0)cin>>a[i];}
template<typename T>inline void read_arr(v(v(T))&a){F(i,a.size(),0)F(j,a[i].size(),0)cin>>a[i][j];}

template<typename T>inline void write_arr(T&a){F(i,a.size(),0)cout<<a[i]<<' ';cout<<endl;}
template<typename T>inline void write_arr(v(v(T))&a){F(i,a.size(),0){F(j,a[i].size(),0)cout<<a[i][j]<<' ';cout<<endl;}}
template<typename T>inline void write_arr(v(v(v(T)))&a){F(i,a.size(),0){F(j,a[i].size(),0){F(k,a[i][j].size(),0)cout<<a[i][j][k]<<' ';cout<<endl;}cout<<endl;}}
template<typename T1,typename T2>inline void write_arr(v(v(p(T1,T2)))&a){F(i,a.size(),0){F(j,a[i].size(),0)cout<<a[i][j].first<<' '<<a[i][j].second<<endl;cout<<endl;}}



main()
{ 
  string a;
  cin>>a;
  int n=a.size(),num=1;
  string cur="";
  cur+=a[0];
  F(i,n,1)
  {
  if(a[i]==cur[cur.size()-1])
  num--,cur.erase(cur.end()-1);
  else num++,cur+=a[i];
  }
  cout<<(num?"No":"Yes");
}