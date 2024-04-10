#include<bits/stdc++.h>
using namespace std;
vector<string> split(const string &str, char sep){
  vector<string> v;
  stringstream ss(str);
  string buffer;
  while( getline(ss, buffer, sep) ) {
    v.push_back(buffer);
  }
  return v;
}
int s2i(string s){
  stringstream ss(s);
  int x;
  ss>>x;
  return x;
}
int main(){
  int T;
  string tmp;
  getline(cin,tmp);
  T=s2i(tmp);
  while(T--){
    getline(cin,tmp);
    int n,m;
    n=s2i(tmp);
    vector<string> name(n);
    map<string,int> ms;
    getline(cin,tmp);
    name=split(tmp,' ');
    for(int i=0;i<n;i++) ms[name[i]]=i;
    getline(cin,tmp);
    m=s2i(tmp);
    int who[m];
    memset(who,-1,sizeof(who));
    string chat[m],out[m];
    vector<string> v[m];
    for(int i=0;i<m;i++){
      getline(cin,chat[i]);
      out[i]=chat[i];
      for(int j=0;j<(int)chat[i].size();j++)
	if(!isalpha(chat[i][j])&&!isdigit(chat[i][j])) chat[i][j]=' ';

      v[i]=split(chat[i],' ');
      if(out[i][0]!='?'){
	who[i]=ms[v[i][0]];
	v[i].erase(v[i].begin());
      }
      /*//
      sort(v[i].begin(),v[i].end());
      v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
      cout<<who[i]<<":";
      for(int j=0;j<(int)v[i].size();j++) cout<<v[i][j]<<" ";
      cout<<endl;
      //*/
    }
    while(1){
      int t=n,idx=-1;
      bool used[n];
      for(int i=0;i<m;i++){
	if(who[i]>=0) continue;
	memset(used,0,sizeof(used));
	if(i>0&&who[i-1]>=0) used[who[i-1]]=1; 
	if(i+1<m&&who[i+1]>=0) used[who[i+1]]=1; 
	for(int j=0;j<(int)v[i].size();j++){
	  if(ms.find(v[i][j])==ms.end()) continue;
	  used[ms[v[i][j]]]=1;
	}
	int r=0;
	for(int j=0;j<n;j++) r+=!used[j];
	if(idx<0||r<t){
	  t=r;
	  idx=i;
	}
      }
      if(t==0||idx<0) break;
      memset(used,0,sizeof(used));
      if(idx>0&&who[idx-1]>=0) used[who[idx-1]]=1; 
      if(idx+1<m&&who[idx+1]>=0) used[who[idx+1]]=1;
      for(int j=0;j<(int)v[idx].size();j++){
	if(ms.find(v[idx][j])==ms.end()) continue;
	used[ms[v[idx][j]]]=1;
      }
      for(int j=0;j<n;j++){
	if(used[j]) continue;
	//cout<<idx<<" "<<j<<endl;
	who[idx]=j;
	break;
      }
    }
    
    bool f=1;
    for(int i=0;i<m;i++) f&=who[i]>=0;
    if(f){
      for(int i=0;i<m;i++){
	cout<<name[who[i]]<<":";
	for(int j=0,x=0;j<(int)out[i].size();j++){
	  if(x) cout<<out[i][j];
	  x|=out[i][j]==':';
	}
	cout<<endl;
      }
    }else cout<<"Impossible"<<endl;
  }
  return 0;
}