#include<bits/stdc++.h>
using namespace std;
#define int long long
char buf[256];
signed main(){
  int n;
  scanf("%lld",&n);
  stack<int> cur;
  set<int> si;
  int tmp=1,ans=0;
  for(int i=0;i<n*2;i++){
    scanf("%s",buf);
    string s(buf);
    if(s=="add"){
      int x;
      scanf("%lld",&x);
      cur.push(x);
    }
    if(s=="remove"){
      if(cur.empty()||cur.top()==tmp){
	if(!cur.empty()) cur.pop();
	tmp++;
      }else{
	while(!cur.empty()){
	  //cout<<cur.top()<<endl;
	  si.insert(cur.top());
	  cur.pop();
	}
	//cout<<tmp<<endl;
	si.erase(tmp);
	tmp++;
	ans++;
      }
    }
  }
  printf("%lld\n",ans);
  return 0;
}