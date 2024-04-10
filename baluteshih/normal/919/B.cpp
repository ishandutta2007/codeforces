#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ll long long
#define iop(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int k;

void dfs(int f,int n,int m,string s)
{
	if(n==1 && m<10)
	{
		k--;
		if(!k) cout << s << (char)(m+'0') << "\n";
		return;
	} 
	else if(n==1 && m>=10) return;
	for(int i=f;k && i<=m && i<10;i++)
		dfs(0,n-1,m-i,s+(char)(i+'0'));
}

int main()
{
	cin >> k;
	for(int n=2;k>0;n++)
		dfs(1,n,10,"");
}