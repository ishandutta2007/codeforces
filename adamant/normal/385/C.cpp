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
#define pf push_front
#define mp make_pair
#define pb push_back
#define sz size
const double PI=4*atan(1);


/* input */

 template<typename T>istream& operator >> ( std::istream& in,v(T)&a){tr11(a,it)in>>*it;return in;}
 template<typename T1,typename T2>istream& operator >>( std::istream& in,p(T1,T2)&a){in>>a.first>>a.second;return in;}
 
/* output */
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,p(T1,T2)&a){out<<a.first<<' '<<a.second;return out;}
 
 template<typename T>ostream& operator << ( std::ostream& out,v(T)&a){tr11(a,it){out<<*it;out<<endl;}return out;}
 template<typename T>ostream& operator << ( std::ostream& out,set<T>&a){tr11(a,it){out<<*it;out<<endl;}return out;}
 
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,map<T1,T2>&a){tr11(a,it){out<<*it;out<<endl;}return out;}

#define ONLINE_JUDGE

main()
 {
ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
 freopen("input.txt","rt",stdin);
 freopen("output.txt","wt",stdout);
#endif
	int n;
cin>>n;
	int a[n];
	F(i,n,0)
        cin>>a[i];
	int m;
	cin>>m;
	
	const int N = 10000100;
	v(int) lp(N+1,0);
	int pr[700000];
int sz=0;
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr[sz++]=i;
		}
		for (int j=0; j<sz && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}
	int primes[sz+1];
	
	F(i,sz+1,0)
primes[i]=0;
	F(i,n,0)
	{
	while(a[i]!=1)	
	{primes[lower_bound(pr,pr+sz,lp[a[i]])-pr]++;
int c=lp[a[i]];
        while(!(a[i]%c))a[i]/=c;}
	}
	
	int sums[sz+2];
	F(i,sz+2,0)
sums[i]=0;
	F(i,sz+1,0)
	sums[i+1]=sums[i]+primes[i];
	F(i,m,0)
	{
	int l,r;
	cin>>l>>r;
	int i1=lower_bound(pr,pr+sz,l)-pr,i2=lower_bound(pr,pr+sz,r)-pr;	
if(pr[i2]>r)
i2--;
if(pr[i1]>r)
cout<<0<<endl;
else
cout<<sums[i2+1]-sums[i1]<<endl;
	}
 }