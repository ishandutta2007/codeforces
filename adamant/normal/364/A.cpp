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
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <ios>

using namespace std;

#define tr(c, it) for(typeof(c.begin()) it=c.begin(); it != c.end(); it++)
#define RF(i,x,st) for(int i=x-1;i>=st;i--)
#define F(i,x,st) for(int i=st;i<x;i++)
#define Fb(i,b,st) for(int i=st;b;i++)
#define rall(c) c.rbegin(),c.rend()
#define all(c) c.begin(),c.end()
#define p(i,j) pair< i , j >
#define INF 1000000000000ll
#define v(i) vector< i >
#define d(i) deque< i >
#define ld long double
#define int long long
#define pf push_front
#define mp make_pair
#define pb push_back


template<typename T>inline void read_arr(T&a){F(i,a.size(),0)cin>>a[i];}
template<typename T>inline void read_arr(v(v(T))&a){F(i,a.size(),0)F(j,a[i].size(),0)cin>>a[i][j];}
template<typename T1,typename T2>inline void read_arr(v(p(T1,T2))&a){F(i,a.size(),0)cin>>a[i].first>>a[i].second;}

template<typename T>inline void write_arr(T&a){F(i,a.size(),0)cout<<a[i]<<' ';cout<<endl;}

/* vector output */
template<typename T>inline void write_arr(v(v(T))&a){F(i,a.size(),0){F(j,a[i].size(),0)cout<<a[i][j]<<' ';cout<<endl;}}
template<typename T>inline void write_arr(v(v(v(T)))&a){F(i,a.size(),0){F(j,a[i].size(),0){F(k,a[i][j].size(),0)cout<<a[i][j][k]<<' ';cout<<endl;}cout<<endl;}}
template<typename T1,typename T2>inline void write_arr(v(p(T1,T2))&a){F(i,a.size(),0)cout<<a[i].first<<' '<<a[i].second<<endl;}
template<typename T1,typename T2>inline void write_arr(v(v(p(T1,T2)))&a){F(i,a.size(),0){F(j,a[i].size(),0)cout<<a[i][j].first<<' '<<a[i][j].second<<endl;cout<<endl;}}

/* deque output */
template<typename T>inline void write_arr(d(d(T))&a){F(i,a.size(),0){F(j,a[i].size(),0)cout<<a[i][j]<<' ';cout<<endl;}}
template<typename T>inline void write_arr(d(d(d(T)))&a){F(i,a.size(),0){F(j,a[i].size(),0){F(k,a[i][j].size(),0)cout<<a[i][j][k]<<' ';cout<<endl;}cout<<endl;}}
template<typename T1,typename T2>inline void write_arr(d(p(T1,T2))&a){F(i,a.size(),0)cout<<a[i].first<<' '<<a[i].second<<endl;}
template<typename T1,typename T2>inline void write_arr(d(d(p(T1,T2)))&a){F(i,a.size(),0){F(j,a[i].size(),0)cout<<a[i][j].first<<' '<<a[i][j].second<<endl;cout<<endl;}}

#define ONLINE_JUDGE

int gcd(int a, int b){return b?gcd(b,a%b):a;}

main()
{ 
#ifndef ONLINE_JUDGE
  freopen("input.txt","rt",stdin);
  freopen("output.txt","wt",stdout);
#endif
  
  int a;
  string s;
  cin>>a>>s;
  int n=s.size();
  v(int) sum(n);
  
  sum[0]=s[0]-'0';
  
  for(int i=1;i<n;i++)
  sum[i]=sum[i-1]+s[i]-'0';
  
  v(v(int)) sum_str(n,v(int)(n));
  
  for(int i=0;i<n;i++)
  sum_str[0][i]=sum[i];
  for(int i=0;i<n;i++)
  sum_str[i][0]=s[i]-'0';
  
  v(int) count(40000,0);
  
  for(int i=1;i<n;i++)
  for(int j=0;i+j<n;j++)
  sum_str[i][j]=sum_str[i-1][j]+s[i+j]-s[i-1];
  int ans=0;
int count_without_0=0;
  for(int i=0;i<n;i++)
  for(int j=0;i+j<n;j++)
  {count[sum_str[i][j]]++;
if(sum_str[i][j]!=0)
count_without_0++;
  if(a==0)
  ans+=2*(count[0]+(sum_str[i][j]==0?count_without_0:0));
  else if(sum_str[i][j] && !(a%sum_str[i][j]) && a/sum_str[i][j]<40000)
  ans+=2*count[a/sum_str[i][j]];
  if(sum_str[i][j]*sum_str[i][j]==a)
  ans--;
  }
  
  
  cout<<ans<<endl;
}