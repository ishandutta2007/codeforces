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
int n,m,k,coun;
v(string) a;
int cc=0;
void dfs(int x,int y)
{
	a[x][y]='+';
	cc++;
	if(cc==coun-k)
	return;
	if(a[x-1][y]=='.')
	if(cc==coun-k)
	return;
	else
	dfs(x-1,y);
	if(a[x][y-1]=='.')
	if(cc==coun-k)
	return;
	else
	dfs(x,y-1);
	if(a[x][y+1]=='.')
	if(cc==coun-k)
	return;
	else
	dfs(x,y+1);
	if(a[x+1][y]=='.')
	if(cc==coun-k)
	return;
	else
	dfs(x+1,y);
}

main()
 {
ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
 freopen("input.txt","rt",stdin);
 freopen("output.txt","wt",stdout);
#endif
	cin>>n>>m>>k;
	a.assign(n+2,string(m+2,'#'));
	int x,y;
	F(i,n+1,1)
	F(j,m+1,1)
	{cin>>a[i][j];
	if(a[i][j]=='.')
	coun++,x=i,y=j;}
	
	dfs(x,y);
	
	F(i,n+1,1)
	{F(j,m+1,1)
	if(a[i][j]=='.')
	cout<<'X';
	else if(a[i][j]=='+')
	cout<<'.';
	else
	cout<<'#';cout<<endl;}

 }