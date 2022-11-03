#include<bits/stdc++.h>
using namespace std;

signed main(){
  int n,m;
  scanf("%d %d",&n,&m);
  int a[n];
  for(int i=0;i<n;i++) scanf("%d",a+i);
  int l[m],r[m];
  for(int i=0;i<m;i++) scanf("%d %d",l+i,r+i);
  vector<int> v(n);
  for(int i=0;i<n;i++) v[i]=a[i];
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  unordered_map<int,int> mi;
  for(int i=0;i<(int)v.size();i++) mi[v[i]]=i;
  int c[n];
  memset(c,0,sizeof(c));
  for(int i=0;i<n;i++) c[mi[a[i]]]++;
  vector<int> s;
  for(int i=0;i<(int)v.size();i++){
    if(c[mi[v[i]]]<v[i]) continue;
    s.push_back(v[i]);
    //cout<<v[i]<<endl;
  }
  int sz=s.size();
  vector<int> im[sz];
  for(int i=0;i<sz;i++){
    im[i].resize(n+1);
    im[i][0]=0;
    for(int j=0;j<n;j++)
      im[i][j+1]=im[i][j]+(s[i]==a[j]);
  }
  for(int i=0;i<m;i++){
    l[i]--;
    int ans=0;
    for(int j=0;j<sz;j++)
      ans+=s[j]==(im[j][r[i]]-im[j][l[i]]);
    printf("%d\n",ans);
  }
  return 0;
}