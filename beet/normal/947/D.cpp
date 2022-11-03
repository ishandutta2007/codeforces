#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  string s,t;
  cin>>s>>t;
  vector<Int> x(s.size()+1,0),y(t.size()+1,0);
  for(Int i=0;i<(Int)s.size();i++) x[i+1]=x[i]+(s[i]!='A');
  for(Int i=0;i<(Int)t.size();i++) y[i+1]=y[i]+(t[i]!='A');
  
  vector<Int> u(s.size(),0),v(t.size(),0);
  u[0]=(s[0]=='A');v[0]=(t[0]=='A');
  for(Int i=1;i<(Int)s.size();i++) u[i]=(u[i-1]+1)*(s[i]=='A');
  for(Int i=1;i<(Int)t.size();i++) v[i]=(v[i-1]+1)*(t[i]=='A');

  if(0){
    for(int i=0;i<(Int)s.size();i++) cout<<i<<" "<<u[i]<<endl;
    cout<<endl;
    for(int i=0;i<(Int)t.size();i++) cout<<i<<" "<<v[i]<<endl;
  }
  
  Int q;
  cin>>q;
  for(Int i=0;i<q;i++){
    Int a,b,c,d;
    cin>>a>>b>>c>>d;
    a--;c--;
    Int n=(x[b]-x[a]);
    Int m=(y[d]-y[c]);
    Int p=min(b-a,u[b-1]);
    Int q=min(d-c,v[d-1]);
    //cout<<n<<" "<<m<<" "<<p<<" "<<q<<endl;
    if(p==q&&n==0) cout<<(m==0);
    else cout<<((p>=q)&&((n<m)||(n==m&&((p-q)%3==0)))&&((m-n)%2==0));
  }
  cout<<endl;
  return 0;
}