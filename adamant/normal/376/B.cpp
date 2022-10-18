#include <bits/stdc++.h>

using namespace std;

#define tr(c, it)  for(typeof(c.begin()) it=c.begin();  it != c.end(); it++)
#define tr11(c, it)  for(auto it=c.begin();  it != c.end(); it++)
#define RF(i,x,st) for(int i=x-1;i>=st;i--)
#define F(i,x,st) for(long i=st;i<x;i++)
#define Fb(i,b,st) for(int i=st;b;i++)
#define rall(c) c.rbegin(),c.rend()
#define all(c) c.begin(),c.end()
#define p(i,j) pair< i , j >
#define INF 10000000000000ll
#define SP system("pause")
#define v(i) vector< i >
#define d(i) deque< i >
#define ld long double
#define int long long
#define pf push_front
#define mp make_pair
#define pb push_back
#define sz size

const double PI=4*atan(1);

/* input */

 template<typename T>istream& operator >> ( std::istream& in,v(T)&a){tr11(a,it)in>>*it;return in;}
 template<typename T1,typename T2>istream& operator >>( std::istream& in,p(T1,T2)&a){in>>a.first>>a.second;return in;}
 
/* output */
 template<typename T>ostream& operator << ( std::ostream& out,v(T)&a){tr11(a,it){out<<*it;out<<endl;}return out;}
 template<typename T>ostream& operator << ( std::ostream& out,set<T>&a){tr11(a,it){out<<*it;out<<endl;}return out;}
 
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,p(T1,T2)&a){out<<a.first<<' '<<a.second;return out;}
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,map<T1,T2>&a){tr11(a,it){out<<*it;out<<endl;}return out;}


#define ONLINE_JUDGE

main()
 {
ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
 freopen("input.txt","rt",stdin);
 freopen("output.txt","wt",stdout);
#endif
	int n,m;
	cin>>n>>m;
	
	v(int) count_in(n,0);
	v(int) count_out(n,0);
	
	int a,b,c;
	F(i,m,0)
	{
	cin>>a>>b>>c;
	count_out[a-1]+=c;
	count_in[b-1]+=c;
	}
	int sum=0;
	F(i,n,0)
	sum+=max(0ll,count_out[i]-count_in[i]);
	cout<<sum<<endl;
 }