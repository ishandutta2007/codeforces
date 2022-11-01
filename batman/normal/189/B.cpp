#include <bits/stdc++.h>
using namespace std;
#define l long long
l n,m,a;
main(){cin>>n>>m;for(l i=0;i<=n;i++)for(l j=0;j<=m;j++)a+=min(i,n-i)*min(j,m-j);cout<<a;}