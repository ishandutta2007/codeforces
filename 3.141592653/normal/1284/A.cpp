#include<cstdio>
#include<iostream>
#include<cmath>
#define PI (acos(-1))
#include<queue>
using std::priority_queue;
#include<map>
using std::map;
#define ll long long
#include<set>
using std::set;
typedef double db;
#include<cstring>
#include<cstdlib>
#define int ll
#include<ctime>
struct pii
{int x,y;};
inline bool operator<(const pii x,const pii y)
{return x.x<y.x;}
const int ntt=998244353;
const int rq=1e9+7;
using std::cin;
using std::cout;
using std::endl;
#define errlog(...) fprintf(stderr,__VA_ARGS__)
#define In(R) (cin>>R)
#define Out(R) (cout<<R)
#define Ln(R) (cout<<R<<endl)
#define IN In
#define OUT Out
#define OUt Out
#define OuT Out
#define LN Ln
#define iN In
#define oUt Out
#define oUT Out
#define lN Ln
#define Lin Ln 
#include<string>
char str[1111111];
std::string s[1111],t[1111];
int n,m,q;
std::string r[2222];
void exec()
{
In(n),IN(m);
	register int i;
	for(i=1;i<=n;i++)In(s[i]);
	for(i=1;i<=m;i++)In(t[i]);
	for(i=1;i<=2020;i++)
	{
		r[i]=s[(i-1)%n+1]+t[(i-1)%m+1];
	}
	In(q);
	while(q--)
	{
		int g;
		In(g);
		g=g%(n*m)+n*m;
		Ln(r[g]);
	}
}
signed main()
{
	std::ios::sync_with_stdio(0);
	int T=1;
	
	//In(T);
	
	while(T--)exec();
}