#include <algorithm>
#include <iostream>
#include <iterator>
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
#define rall(c) c.rbegin(),c.rend()
#define all(c) c.begin(),c.end()
#define SP system("PAUSE")
#define p(i,j) pair<i,j>
#define ld long double
#define v(i) vector<i>
#define d(i) deque<i>
#define int long long
#define mp make_pair
#define pb push_back
#define pf push_front

template<typename T>inline void read_arr(T&a){F(i,a.size(),0)cin>>a[i];}
inline void read_arr(v(v(int))&a){F(i,a.size(),0)F(j,a[i].size(),0)cin>>a[i][j];}

template<typename T>inline void write_arr(T&a){F(i,a.size(),0)cout<<a[i]<<' ';cout<<endl;}
inline void write_arr(v(v(int))&a){F(i,a.size(),0){F(j,a[i].size(),0)cout<<a[i][j]<<' ';cout<<endl;}}
inline void write_arr(v(v(p(int,int)))&a){F(i,a.size(),0){F(j,a[i].size(),0)cout<<a[i][j].first<<' '<<a[i][j].second<<endl;cout<<endl;}}
int EPS=1e9+9;

int bin_pow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res *= a,res%=EPS;
		a *= a;
		a%=EPS;
		n >>= 1;
	}
	return res%EPS;
}
  main()
 {   
  int n,m,k;
  cin>>n>>m>>k;
  int ans=0;
  int kk=n/k;
  
  if(n-kk*k>=m)
  {cout<<m%EPS;return 0;}
  
  m-=n-kk*k;
  ans+=n-kk*k;
  ans%=EPS;
  n-=n-kk*k;
  int tmp=(k-1)*kk;
  //cout<<ans<<endl;
  if(tmp>=m)
  {cout<<(ans+m)%EPS;return 0;}
  
  int mm=m-tmp;
  //cout<<mm<<' '<<kk<<endl;
  ans+=(k-1)*(kk-mm);
  //cout<<ans<<endl;
  ans%=EPS;
  int temp=k;
  int um_by=bin_pow(2,mm+1);
  um_by=(um_by-2+EPS)%EPS;
  //cout<<um_by<<endl;
  //cout<<temp<<endl;
  temp*=um_by;
  temp%=EPS;
  ans+=temp;
  ans%=EPS;
  cout<<ans%EPS;
  //SP;
 }