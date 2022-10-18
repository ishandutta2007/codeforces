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
#define rall(c) c.rbegin(),c.rend()
#define F(i,x) for(int i=0;i<x;i++)
#define all(c) c.begin(),c.end()
#define p(i,j) pair<i,j>
#define ld long double
#define v(i) vector<i>
#define d(i) deque<i>
#define int long long
#define mp make_pair
#define pb push_back


  main()
 {   
    string a;
    int n;
    cin>>a>>n;
    int u=0;
    v(int) count(26,0);
    int nn=a.size();
    F(i,nn)
    count[a[i]-'a']++;
    
    F(i,26)
    u+=bool(count[i]);
    if(u>n)
    {cout<<-1<<endl;return 0;}
    
    int l=1,r=1e4;
    string ans;
    while(l<r)
    {
     int m=l+(r-l)/2;
     int cou=0;
     F(i,26)
     cou+=count[i]/m+bool(count[i]%m);
     if(cou<=n)
     r=m;
     else
     l=m+1;
    }
    cout<<r<<endl;
    F(i,26)
    ans.append(count[i]/r+bool(count[i]%r),i+'a');
    if(ans.size()<n)
    ans.append(n-ans.size(),a[0]);
    cout<<ans<<endl;
 }