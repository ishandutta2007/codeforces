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
	int n,m,p;
	cin>>n>>m>>p;
	
	v(int) a(n);
	cin>>a;
	unordered_map<int,int> b;
	int t;
	for(int i=0;i<m;i++)
	{cin>>t;b[t]++;}
	
	v(v(int)) moduls(p);
	
	for(int i=0;i<n;i++)
	moduls[i%p].pb(a[i]);
	v(int) ans;
	for(int i=0;i<p;i++)
	{
		if(moduls[i].size()<m)
		continue;
		unordered_map<int,int> cur;
		for(int j=0;j<m;j++)
		cur[moduls[i][j]]++;
		int non_ok=0;
		tr11(cur,it)
		non_ok+=it->second!=b[it->first];
		tr11(b,it)
                non_ok+=cur[it->first]==0 && it->second;
		if(non_ok==0)
		ans.pb(i+1);
		int kk=moduls[i].size();
		for(int j=m;j<kk;j++)
		{
		cur[moduls[i][j-m]]--;
		if(cur[moduls[i][j-m]]==b[moduls[i][j-m]])	
		non_ok--;
		else if(cur[moduls[i][j-m]]+1==b[moduls[i][j-m]])
		non_ok++;
		cur[moduls[i][j]]++;
		if(cur[moduls[i][j]]==b[moduls[i][j]])	
		non_ok--;
		else if(cur[moduls[i][j]]-1==b[moduls[i][j]])	
		non_ok++;
		if(non_ok==0)
		ans.pb(p*(j-m+1)+i+1);
		}
	}
	cout<<ans.size()<<endl;
	if(ans.size())
	{sort(all(ans));cout<<ans;}
 }