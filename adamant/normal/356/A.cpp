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

main()
{ 
#ifndef ONLINE_JUDGE
  freopen("input.txt","rt",stdin);
  freopen("output.txt","wt",stdout);
#endif
  
  int n,m;
  cin>>n>>m;
  
  v(int) l(m),r(m),x(m);
  
  F(i,m,0)
  cin>>l[i]>>r[i]>>x[i];
  
  set<int> knights;
  
  F(i,n,0)
  knights.insert(i+1);
  
  v(int) ans(n,0);
  F(i,m,0)
  {
        set<int>::iterator it=knights.lower_bound(l[i]),it1=it,it2=knights.lower_bound(r[i]);
        while(it1!=it2)
        {
         if(*it1!=x[i])   
         ans[(*it1)-1]=x[i];
         it1++;
        }
        if(it1!=knights.end() && *it1!=x[i])   
        ans[(*it1)-1]=x[i];
        if(it2!=knights.end() && *it2==r[i])
        it2++;
        knights.erase(it,it2);
        knights.insert(x[i]);
  }
  ans[x[m-1]-1]=0;
  
  write_arr(ans);
}