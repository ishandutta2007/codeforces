#include<bits/stdc++.h>
using namespace std;
using Int = long long;
Int ms=(1<<8)-1;
Int expr(string s,Int& p);
Int term(string s,Int& p);
Int factor(string s,Int& p);
Int number(string s,Int& p);
Int expr(string s,Int& p){
  Int res=term(s,p);
  while(p<(Int)s.size()){
    if(s[p]=='|'){
      p++;
      res|=term(s,p);
      continue;
    }
    break;
  }
  return res;
}
Int term(string s,Int& p){
  Int res=factor(s,p);
  while(p<(Int)s.size()){
    if(s[p]=='&'){
      p++;
      res&=factor(s,p);
      continue;
    }
    break;
  }
  return res;
}
Int factor(string s,Int& p){
  if(s[p]=='!'){
    p++;
    return (~factor(s,p))&ms;
  }
  if(s[p]=='('){
    p++;
    Int res=expr(s,p);
    assert(s[p]==')');
    p++;
    return res;
  }
  return number(s,p);
}
Int calc(char c){
  if(c=='x') return 0b00001111;
  if(c=='y') return 0b00110011;
  if(c=='z') return 0b01010101;
  assert(0);
}
Int number(string s,Int& p){
  char c=s[p++];
  return calc(c);
}
Int dp[1<<8];
Int dp2[2][2][1<<8];
string st[1<<8];
string st2[2][2][1<<8];
using T =  tuple<Int, Int, Int, Int>;
signed main(){
  for(Int i=0;i<(1<<8);i++) dp[i]=100;
  for(Int i=0;i<(1<<8);i++)
    for(Int a=0;a<2;a++)
      for(Int b=0;b<2;b++)
	dp2[a][b][i]=100;
  priority_queue<T,vector<T>,greater<T> > pq;
  string t="xyz";
  for(Int i=0;i<(Int)t.size();i++){
    Int k=calc(t[i]);
    dp2[0][0][k]=1;
    st2[0][0][k]=string(1,t[i]);
    pq.emplace(dp2[0][0][k],0,0,k);
  }
  for(Int i=0;i<(Int)t.size();i++){
    Int k=~calc(t[i])&ms;
    dp2[0][0][k]=2;
    st2[0][0][k]=string("!")+string(1,t[i]);
    pq.emplace(dp2[0][0][k],0,0,k);
  }
  while(!pq.empty()){
    Int d,a,b,k;
    tie(d,a,b,k)=pq.top();pq.pop();
    if(dp[k]>dp2[a][b][k]||
       (dp[k]==dp2[a][b][k]&&st[k]>st2[a][b][k])){
      dp[k]=dp2[a][b][k];
      st[k]=st2[a][b][k];
    }
    if(dp2[a][b][k]<d) continue;
    assert(dp2[a][b][k]==(Int)st2[a][b][k].size());
    //cout<<a<<" "<<b<<" "<<bitset<8>(k)<<":"<<dp2[a][b][k]<<" "<<st2[a][b][k]<<endl;

    {
      Int na=a,nb=0;
      Int nk=(~k)&ms,c=3;
      string ns=string("!(")+st2[a][b][k]+string(")");
      if(dp2[na][nb][nk]>dp2[a][b][k]+c||
	 (dp2[na][nb][nk]==dp2[a][b][k]+c&&st2[na][nb][nk]>ns)){
	dp2[na][nb][nk]=dp2[a][b][k]+c;
	st2[na][nb][nk]=ns;
	pq.emplace(dp2[na][nb][nk],na,nb,nk);
      }
    }
    
    for(int i=0;i<(1<<8);i++){
      for(int j=0;j<2;j++){
	if(dp2[0][j][i]==100) continue;
	{
	  string fs=(j?string("(")+st2[0][j][i]+string(")"):st2[0][j][i]);
	  string bs=(b?string("(")+st2[a][b][k]+string(")"):st2[a][b][k]);
	  Int na=a,nb=0;
	  Int nk=k&i;
	  {
	    string ns=fs+string("&")+bs;
	    int nc=ns.size();
	    if(dp2[na][nb][nk]>nc||
	       (dp2[na][nb][nk]==nc&&st2[na][nb][nk]>ns)){
	      dp2[na][nb][nk]=nc;
	      st2[na][nb][nk]=ns;
	      pq.emplace(dp2[na][nb][nk],na,nb,nk);
	    }
	  }
	  {
	    string ns=bs+string("&")+fs;
	    int nc=ns.size();
	    if(dp2[na][nb][nk]>nc||
	       (dp2[na][nb][nk]==nc&&st2[na][nb][nk]>ns)){
	      dp2[na][nb][nk]=nc;
	      st2[na][nb][nk]=ns;
	      pq.emplace(dp2[na][nb][nk],na,nb,nk);
	    }
	  }
	}
	
	{
	  Int na=a,nb=1;
	  Int nk=k|i;
	  {
	    string ns=st2[0][j][i]+string("|")+st2[a][b][k];
	    int nc=ns.size();
	    if(dp2[na][nb][nk]>nc||
	       (dp2[na][nb][nk]==nc&&st2[na][nb][nk]>ns)){
	      dp2[na][nb][nk]=nc;
	      st2[na][nb][nk]=ns;
	      pq.emplace(dp2[na][nb][nk],na,nb,nk);
	    }
	  }
	  {
	    string ns=st2[a][b][k]+string("|")+st2[0][j][i];
	    int nc=ns.size();
	    if(dp2[na][nb][nk]>nc||
	       (dp2[na][nb][nk]==nc&&st2[na][nb][nk]>ns)){
	      dp2[na][nb][nk]=nc;
	      st2[na][nb][nk]=ns;
	      pq.emplace(dp2[na][nb][nk],na,nb,nk);
	    }
	  }
	}
      }
    }
  }
  
  Int n;
  cin>>n;
  for(Int i=0;i<n;i++){
    string s;
    cin>>s;
    Int k=0;
    for(Int j=0;j<8;j++) k=k*2+(s[j]-'0');
    //Int p=0;cout<<bitset<8>(k)<<":"<<st[k]<<endl;assert(expr(st[k],p)==k);
    cout<<st[k]<<endl;
  }
  return 0;
}