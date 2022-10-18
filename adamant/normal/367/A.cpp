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
ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
 freopen("input.txt","rt",stdin);
 freopen("output.txt","wt",stdout);
#endif
	string s;
    int n;
    cin>>s;
	n=s.size();
	int m;
	cin>>m;
	
	v(int) x(n,0),y(n,0),z(n,0);
	if(s[0]=='x')x[0]++;
	if(s[0]=='y')y[0]++;
	if(s[0]=='z')z[0]++;
	for(int i=1;i<n;i++)
	{x[i]=x[i-1],y[i]=y[i-1],z[i]=z[i-1];
	if(s[i]=='x')x[i]++;
	if(s[i]=='y')y[i]++;
	if(s[i]=='z')z[i]++;}
	
	for(int i=0;i<m;i++)
	{
	int a,b;
	cin>>a>>b;
	
	int xx=x[b-1]-(a>1?x[a-2]:0);	
	int yy=y[b-1]-(a>1?y[a-2]:0);
	int zz=z[b-1]-(a>1?z[a-2]:0);
	
	int maxab=max(abs(xx-yy),max(abs(zz-xx),abs(yy-zz)));
	if(maxab>1 && b-a>=2)
	cout<<"NO"<<endl;
	else
	cout<<"YES"<<endl;
	
	}
 }