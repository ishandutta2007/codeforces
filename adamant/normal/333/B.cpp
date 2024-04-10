#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#include <set>
 
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
    int n,m,count=0;
    cin>>n>>m;
    d(p(int,int)) a(m);
    v(bool) x(n,1);
    v(bool) y(n,1);
    
    F(i,m)
    {cin>>a[i].first>>a[i].second;x[a[i].first-1]=0,y[a[i].second-1]=0;}
    for(int i=1;i<n/2;i++)
    {
     if(!x[i] && !y[i] && !x[n-i-1] && !y[n-i-1])   
     continue;
     bool ax[4]={x[i],y[i],x[n-i-1],y[n-i-1]};
     int t=0;
     F(j,4)
     t+=ax[j];
     count+=t;
    }
    if(n%2 && (x[n/2] || y[n/2]) )
    count++;
    cout<<count<<endl;
 }