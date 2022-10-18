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

vector<int> t;
int n;

void init (int nn)
{
	n = nn;
	t.assign (n, 0);
}

int sum (int r)
{
	int result = 0;
	if(r==-1)
	return result;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta)
{
	for (; i < n; i = (i | (i+1)))
		t[i] += delta;
}

int sum (int l, int r)
{
	return sum (r) - sum (l-1);
}

void init (vector<int> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		inc (i, a[i]);
}

 main()
 { 
#ifndef ONLINE_JUDGE
 freopen("input.txt","rt",stdin);
 freopen("output.txt","wt",stdout);
#endif
  int n;
  cin>>n;
  
  v(p(int,int)) a(n);
  for(int i=0;i<n;i++)
  {
		int t;
		cin>>t;
		a[i].first=t;
		a[i].second=i+1;
  }
  sort(all(a));
  int k;
  cin>>k;
  
  v(int) prefix(n,0);
  v(int) suffix(n,0);
  F(i,k,1)
  prefix[0]+=a[i].first-a[0].first;
  F(i,k,1)
  suffix[n-1]+=a[n-1].first-a[n-i-1].first;
  F(i,n,k)
  {prefix[i-k+1]=prefix[i-k]-(k-1)*(a[i-k+1].first-a[i-k].first)+(a[i].first-a[i-k+1].first);}
  F(i,n,k)
  {suffix[n-i+k-2]=suffix[n-i+k-1]-(k-1)*(a[n-i+k-1].first-a[n-i+k-2].first)+(a[n-i+k-2].first-a[n-i-1].first);}
  v(int) sum(n,0);
  F(i,k,1)
  sum[0]+=sum[0]+i*(a[i].first-a[i-1].first);
  int min_sum_ind=0;
  F(i,n,k)
  {sum[i-k+1]=sum[i-k]-prefix[i-k]+suffix[i];
  if(sum[i-k+1]<sum[min_sum_ind])
  min_sum_ind=i-k+1;
  }
  for(int i=min_sum_ind;i<min_sum_ind+k;i++)
  cout<<a[i].second<<' ';
  cout<<endl;
 }