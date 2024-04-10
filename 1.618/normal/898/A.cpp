// POJ 
// USACO
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#define inf 2139062143
#define mod 1000000007
//data:
using namespace std;
int n;
int main(){
//	freopen("ryz.in","r",stdin);
//	freopen("my.out","w",stdout);
//	ios::sync_with_stdio(false);
	scanf("%d",&n);
	if(n%10>5) printf("%d\n",n/10*10+10);
	else printf("%d\n",n/10*10);
	return 0;
}