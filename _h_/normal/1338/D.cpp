#include <bits/stdc++.h>
using namespace std;
main(){
int n,a,b,t;
cin>>n;
vector<vector<int>>g(n);
for(int i=1;i<n;i++){
cin>>a>>b;
g[a-1].push_back(b-1);
g[b-1].push_back(a-1);}
function<pair<int,int>(int,int)>l=[&](int v,int p){
pair<int,int>a(0,v);
for(auto u:g[v])if(u!=p){
if(g[u].size()==2){
auto c=l(g[u][0]+g[u][1]-v,u);
c.first+=1;
a=max(a,c);}
if(g[u].size()>2)a=max(a,l(u,v));}
a.first+=g[v].size()-2;
return a;};
while(g[t].size()==1)t++;
cout<<2+l(l(t,-1).second,-1).first<<endl;}