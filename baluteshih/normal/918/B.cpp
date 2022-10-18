#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <bitset> 
#include <map>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ll long long
using namespace std;

struct mode
{
	int a,b,c,d;
	bool operator<(const mode&x)const{
		if(a==x.a && b==x.b && c==x.c) return d<x.d;
		if(a==x.a && b==x.b) return c<x.c;
		if(a==x.a) return b<x.b;
		return a<x.a;
	}
};

map<mode,string> vis;

int main()
{
	string s;
	int n,m,a,b,c,d;
	cin >> n >> m;
	while(n--)
		cin >> s,scanf("%d.%d.%d.%d",&a,&b,&c,&d),vis[mode{a,b,c,d}]=s;
	while(m--)
		cin >> s,scanf("%d.%d.%d.%d;",&a,&b,&c,&d),printf("%s %d.%d.%d.%d; #",s.c_str(),a,b,c,d),cout << vis[mode{a,b,c,d}] << "\n";
}