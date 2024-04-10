#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 50050
int n,k;
int r[MAX_N+1],r2[MAX_N+1];
int t[MAX_N+1];
bool compare_sa(int i,int j){
  if(r[i]!=r[j]) return r[i]<r[j];
  else{
    int ri=i+k<=n?r[i+k]:-1;
    int rj=j+k<=n?r[j+k]:-1;
    return ri<rj;
  }
}
void constract_sa(string& S, int *sa){
  n=S.length();
  for(int i=0;i<=n;i++){
    sa[i]=i;
    r[i]=i<n?S[i]:-1;
  }
  for(k=1;k<=n;k*=2){
    sort(sa,sa+n+1,compare_sa);
    t[sa[0]]=0;
    for(int i=0;i<=n;i++){
      t[sa[i]]=t[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
    }
    for(int i=0;i<=n;i++){
      r[i]=t[i];
    }
  }
}

map<string,vector<int> > mv;
vector<int> count(string &S,int *sa,string& T){
  if(mv.count(T)) return mv[T];
  int sl=S.length(),tl=T.length();
  int a[2],b[2];
  for(int i=0;i<2;i++){
    a[i]=0;
    b[i]=sl;
    while(a[i]+1<b[i]){
      int c=(a[i]+b[i])/2;
      if(S.compare(sa[c],tl,T)<0||
	 (i&&S.compare(sa[c],tl,T)==0)) a[i]=c;
      else b[i]=c;
    }
  }
  vector<int> v;
  if(S.compare(sa[b[0]],tl,T)!=0) return mv[T]=v;
  if(a[1]<sl&&S.compare(sa[a[1]+1],tl,T)==0) a[1]++;
  if(b[0]> 0&&S.compare(sa[b[0]-1],tl,T)==0) b[0]--;
  //cout<<T<<":"<<a[1]<<" "<<b[0]<<endl;
  for(int i=b[0];i<=a[1];i++) v.push_back(sa[i]);
  sort(v.begin(),v.end());
  return mv[T]=v;
}
char buf[MAX_N];
int main(){
  scanf("%s",buf);
  string s(buf);
  int q;
  cin>>q;
  string a[q],b[q];
  for(int i=0;i<q;i++){
    scanf("%s",buf);
    a[i]=string(buf);
    scanf("%s",buf);
    b[i]=string(buf);
  }
  int sa[55555];
  constract_sa(s,sa);
  map<pair<string,string>,int> mps;
  for(int i=0;i<q;i++){
    if(mps.count(make_pair(a[i],b[i]))){
      cout<<mps[make_pair(a[i],b[i])]<<endl;
      continue;
    }
    int ans=s.length();
    vector<int> va=count(s,sa,a[i]);
    vector<int> vb=count(s,sa,b[i]);
    int as=va.size(),bs=vb.size();
    if(!as||!bs){
      cout<<-1<<endl;
      continue;
    }
    int pa=0,pb=0;
    int al=a[i].length(),bl=b[i].length();
    while(pa<as&&pb<bs){
      int ma=max(va[pa]+al,vb[pb]+bl);
      int mi=min(va[pa],vb[pb]);
      ans=min(ans,ma-mi);
      if(ans<=al||ans<=bl) break;
      else if(va[pa]<vb[pb]) pa++;
      else if(va[pa]>vb[pb]) pb++;
    }
    cout<<ans<<endl;
    mps[make_pair(a[i],b[i])]=mps[make_pair(b[i],a[i])]=ans;
  }
  return 0;
}