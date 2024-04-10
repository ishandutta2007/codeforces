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
    int n;
    cin>>n;
    F(i,n*n/2)
    cout<<i+1<<' '<<n*n-i<<endl;
    
 }