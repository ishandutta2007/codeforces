#include <bits/stdc++.h>
#define R(i,n) for(int i=0;i<n;i++)
#define M 500001
using namespace std;int a[M],h[M],c[M],m[M],n,q,x,d,j;vector<int>v[M];long long r;main(){m[1]=1;R(i,M)if(i)for(j=i;j<M;j+=i){v[j].push_back(i);if(i<j)m[j]-=m[i];}cin>>n>>q;R(i,n)cin>>a[i];R(i,q){cin>>x;h[--x]^=1;for(d:v[a[x]])h[x]?r+=m[d]*(c[d]++):r-=m[d]*(--c[d]);cout<<r<<'\n';}return 0;}