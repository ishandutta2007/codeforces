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

#define tr(c, it)  for(typeof(c.begin()) it=c.begin();  it != c.end(); it++)
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

const int m=1000000;
int k;
int q[m+10];

bool ch(int p)
{
    for(int z=0;z<=m;z+=p)
    {int ma=min(z+p-1,m),mi=((z==0)?1:(z+k+1));
    if(mi<=ma && q[mi] < q[ma+1]) 
    return 0;}
    return 1;
}

main()
{
    int n,t;
    
    cin>>n>>k;
    F(i,n,0)
    {cin>>t;
    q[t+1]=1;}
    
    F(i,m+5,0) q[i+1]+=q[i];
    int i;
    for(i=m;i>=2;i--) if(ch(i)) break;
    cout<<i<<endl;
}