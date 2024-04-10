#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int h[N],v[N],d[N],vis[N];
basic_string<int>g[N],g0[N],g1[N],w[N];
queue<int>q,q2,q3;
int main(){ios::sync_with_stdio(0);cin.tie(0);
int n,i,j,k;
for(cin>>n,i=1;i<=n;++i)if(cin>>h[i],h[i])q.push(i);
for(i=1;i<n;++i)cin>>j>>k,g[j]+=k,g[k]+=j;
while(q.size()){
i=q.front(),q.pop();
for(int o:g[i])if(!h[o])h[o]=h[i]+1,q.push(o);
}
for(i=1;i<=n;++i){
for(int o:g[i])if(h[o]==h[i])g0[i]+=o;
else if(h[o]>h[i])g1[i]+=o;
if(v[i]=h[i],g0[i].size())w[h[i]]+=i;
}
for(i=n;i;--i)if(w[i].size()){
memset(d,9,sizeof d);
for(int o:w[i])d[o]=0,q.push(o);
while(q.size()){
while(q.size()||q2.size()){
if(q2.empty()||(q.size()&&d[q.front()]<d[q2.front()]))j=q.front(),q.pop();
else j=q2.front(),q2.pop();
if(vis[j]==i)continue;
vis[j]=i;
for(int o:g0[j])if(d[o]>d[j]+1)d[o]=d[j]+1,q2.push(o);
for(int o:g1[j])if(d[o]>(k=max(0,d[j]-1)))d[o]=k,q3.push(o);
}
swap(q,q3);
}
for(j=1;j<=n;++j)if(!d[j])v[j]=i;
}
for(i=1;i<=n;++i)cout<<h[i]*2-v[i]-1<<' ';
}