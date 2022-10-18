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

int stack[100];

int main()
{
	ll n,top=0,i;
	cin >> n;
	if(n>36)
		return cout << "-1\n",0;
	while(n>=2)
		stack[top++]=8,n-=2;
	if(n==1)
		stack[top++]=4;
	for(i=top-1;i>=0;i--)
		cout << stack[i];
	cout << "\n";
}