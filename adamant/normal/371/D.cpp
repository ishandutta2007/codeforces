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

 main()
 { 
#ifndef ONLINE_JUDGE
 freopen("input.txt","rt",stdin);
 freopen("output.txt","wt",stdout);
#endif
  int n;
  cin>>n;
  
  v(int) a(n);
  cin>>a;
  
  int m;
  cin>>m;
  
  set<int> empty;
  F(i,n,0)
  empty.insert(i);
  v(int) ans(n,0);
  
  for(int i=0;i<m;i++)
  {
		int ty;
		cin>>ty;
		if(ty==1)
		{
			int p,x;
			cin>>p>>x;
			cont:
			if(!empty.count(p-1))
			{
			auto it=empty.lower_bound(p-1);
			if(it!=empty.end())
			{p=(*it)+1;
			goto cont;}
			}
			else
			{
			ans[p-1]+=x;
			if(ans[p-1]>a[p-1])	
			{
			x=ans[p-1]-a[p-1];
			ans[p-1]=a[p-1];
			empty.erase(p-1);
			auto it=empty.lower_bound(p-1);
			if(it!=empty.end())
			{p=(*it)+1;
			goto cont;}
			}
			}
		}
		else
		{
		int k;
		cin>>k;
		cout<<ans[k-1]<<endl;	
		}
  }
 }