#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,m;
  cin>>n>>m;
  string s[n],v[n],a[n],o[n],b[n];
  bool t[n];
  string buf;
  for(int i=0;i<n;i++){
    cin>>s[i];
    cin>>buf;
    cin>>buf;
    t[i]=isdigit(buf[0]);
    if(t[i]) v[i]=buf;
    else{
      a[i]=buf;
      cin>>o[i]>>b[i];
    }
  }
  /*
  for(int i=0;i<n;i++){
    cout<<s[i]<<" ";
    if(t[i]) cout<<v[i]<<" ";
    else cout<<a[i]<<" "<<o[i]<<" "<<b[i];
    cout<<endl;
  }
  */
  map<string,int> ms;
  for(int i=0;i<n;i++) ms[s[i]]=i;
  ms["?"]=n;
  
  string ans,ans2;
  for(int i=0;i<m;i++){
    int tmp[2]={};
    int res[n+1];
    memset(res,0,sizeof(res));
    for(int k=0;k<2;k++){
      res[n]=k;
      for(int j=0;j<n;j++){
	if(t[j]){
	  res[j]=v[j][i]-'0';
	  continue;
	}
	int ba=res[ms[a[j]]],bb=res[ms[b[j]]];
	//cout<<j<<":"<<ba<<" "<<bb<<endl;
	if(o[j]=="AND") res[j]=ba&bb;
	if(o[j]=="OR" ) res[j]=ba|bb;
	if(o[j]=="XOR") res[j]=ba^bb;
      }
      for(int j=0;j<n;j++) tmp[k]+=res[j];
    }
    //cout<<tmp[0]<<" "<<tmp[1]<<endl;
    if(tmp[0]<=tmp[1]) ans+='0';
    else ans+='1';
    if(tmp[0]>=tmp[1]) ans2+='0';
    else ans2+='1';
  }
  cout<<ans<<endl<<ans2<<endl;
  return 0;
}