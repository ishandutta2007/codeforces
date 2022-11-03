#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  set<string> ss;
  string a,b;
  cin>>a>>b;
  ss.insert(a);ss.insert(b);
  cout<<a<<" "<<b<<endl;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    ss.erase(a);
    cout<<*ss.begin()<<" "<<b<<endl;
    ss.insert(b);
  }
  return 0;
}