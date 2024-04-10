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
	string A;
	cin>>A;
	int n=A.size();
	deque<int> a(n);
	F(i,n,0)
	a[i]=A[i]-'0';
	bool fo[4]={0};
	F(i,n,0)
	if(a[i]==1 && !fo[0])
	swap(a[i--],a[0]),fo[0]=1,a.pb(1),a.pop_front();
	else if(a[i]==6 && !fo[1])
	swap(a[i--],a[0]),fo[1]=1,a.pb(6),a.pop_front();
	else if(a[i]==8 && !fo[2])
	swap(a[i--],a[0]),fo[2]=1,a.pb(8),a.pop_front();
	else if(a[i]==9 && !fo[3])
	swap(a[i--],a[0]),fo[3]=1,a.pb(9),a.pop_front();
	int zer_co=0;
	while(a[0]==0)
	zer_co++,a.pop_front(),n--;
	int ost=0;
	F(i,n-4,0)
	{ost=(ost*10+a[i])%7;cout<<a[i];}
	int arr[4]={1,6,8,9};
	F(i,4,0)
	F(j,4,0)
	F(k,4,0)
	F(l,4,0)
	{
		if(i==j || i==k || i==l || j==k || j==l || k==l)
		continue;
		a[n-4]=arr[i];
		a[n-3]=arr[j];
		a[n-2]=arr[k];
		a[n-1]=arr[l];
		int tost=ost;
		F(z,n,n-4)
		{tost=(tost*10+a[z])%7;}
		if(tost==0)
		{cout<<arr[i]<<arr[j]<<arr[k]<<arr[l];goto END;}
	}
	END:
	F(i,zer_co,0)
	cout<<0;
	cout<<endl;
 }