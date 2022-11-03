#include<bits/stdc++.h>
using namespace std;
#define int long long
char buf[1234567];
int MOD=1000000007;
signed main(){
  scanf("%s",buf);
  string s(buf);
  int ans=0,tmp=0;
  reverse(s.begin(),s.end());
  for(int i=0;i<(int)s.size();i++){
    if(s[i]=='a'){
      (ans+=tmp)%=MOD;
      (tmp*=2)%=MOD;
    }else{
      tmp++;
    }
  }
  cout<<ans<<endl;
  return 0;
}