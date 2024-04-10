#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;

int main()
{
	int n,k,i,top;
	cin >> n >> k;
	if(n==1 && k==1)
		return cout << "a\n",0;
	if(k==1)
		return cout << "-1\n",0; 
	if(n<k)
		return cout << "-1\n",0;
	for(i=0;i<n-k+2;i++)
		if(i&1) putchar('b');
		else putchar('a');
	for(top=2;i<n;i++)
		putchar('a'+top),top++;
	puts("");
}