#include<bits/stdc++.h>
using namespace std;
int n,j,a[100000],b[100000],c[100001];
main(){
cin>>n;
for(int i=0;++i<n;)cin>>a[i]>>b[i];for(int i=0;i++<n;)cin>>c[i];
auto f=[&](int v){
for(int i=0;++i<n;)if(a[i]!=v&&b[i]!=v&&c[a[i]]!=c[b[i]])return i;
printf("YES\n%d\n",v);exit(0);};
j=f(1);f(a[j]);f(b[j]);
puts("NO");}