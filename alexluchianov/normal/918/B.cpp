#include <iostream>
#include <map>

using namespace std;
map<string , string> h;

int main()
{
  int n , m;
  cin>>n>>m;
  string s , s2;
  for(int i = 1 ; i <= n ;i++){
    cin>>s>>s2;
    h[s2] = s;
  }
  for(int i = 1 ; i <= m ;i++){
    string com , s;
    cin>>com>>s;
    cout<<com<<" "<<s<<" #";
    s.pop_back();
    cout<<h[s]<<'\n';
  }
  return 0;
}