#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 10000;

map<char, int> isvoyel;

int main()
{
  isvoyel['a'] = isvoyel['e'] =  isvoyel['i'] =  isvoyel['o'] =  isvoyel['u'] = 1;

  string s, t;
  cin >> s >> t;
  if(s.size() != t.size())
    cout << "No";
  else{
    for(int i = 0 ; i < s.size() ; i++){
      if(isvoyel[s[i]] != isvoyel[t[i]]) {
        cout << "No";
        return 0;
      }
    }
    cout << "Yes";
  }
  return 0;
}