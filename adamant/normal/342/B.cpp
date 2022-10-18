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
template<typename T1,typename T2>inline void write_arr(v(v(p(T1,T2)))&a){F(i,a.size(),0){F(j,a[i].size(),0)cout<<a[i][j].first<<' '<<a[i][j].second<<endl;cout<<endl;}}

 main()
 {
        int n,m,s,f,curt=1;
        cin>>n>>m>>s>>f;
        F(i,m,0)
        {
         int t,l,r;
         cin>>t>>l>>r;
ST:
         while(curt<t || curt>t)
         {
                if(f<s)
                {s--,cout<<'L';}
                else
                {s++,cout<<'R';}
                if(f==s)
                return 0;
                curt++;
         }
         curt++;
         if(s>=l && s<=r)
         {cout<<'X';goto NX;}   
         if(f<s)
         {if(s-1>=l && s-1<=r)
         {cout<<'X';goto NX;}   
         else
         {s--,cout<<'L';}}
         else if(f>s)
         if(s+1>=l && s+1<=r)
         {cout<<'X';goto NX;}   
         else
         {s++,cout<<'R';}
         if(f==s)
         return 0;
NX:
if(i==m-1 && f!=s)
goto ST;
        }
        //SP;
 }