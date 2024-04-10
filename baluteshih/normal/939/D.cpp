#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#include <queue>
#include <utility>
using namespace std;
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second

int boss[30];
string a,b;

struct mode
{
	char a,b;
}type[100001];

int Find(int x)
{
	if(boss[x]==x) return x;
	return boss[x]=Find(boss[x]);
}

int main()
{
	int n,i,j,top=0;
	cin >> n >> a >> b;
	for(i=0;i<26;i++)
		boss[i]=i;
	for(i=0;i<n;i++)
		if(Find(a[i]-'a')!=Find(b[i]-'a'))
			type[top++]=mode{a[i],b[i]},boss[Find(a[i]-'a')]=Find(b[i]-'a');
	cout << top << "\n";
	for(i=0;i<top;i++)
		cout << type[i].a << " " << type[i].b << "\n";
}