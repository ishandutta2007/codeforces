#include <iostream>

using namespace std;

int const nmax = 200000;

string s ;
string s2;

int v[5 + nmax];
int seen[5 + nmax];

bool test(int x){
  for(int i = 1 ; i <= s.size() ;i++){
    seen[i] = 0;
  }
  for(int i = 1 ; i <= x ; i++){
    seen[v[i]] = 1;
  }
  int sol = 0;
  for(int i = 1 ; i <= s.size() ;i++){
    if(seen[i] == 0 && sol < s2.size()){
      if(s2[sol + 1] == s[i])
        sol++;
    }
  }
  return (sol == s2.size());
}

int binarysearch(int from , int to){
  if(from < to){
    int mid = (from + to + 1) / 2;
    if(test(mid) == 1)
      return binarysearch(mid , to);
    else
      return binarysearch(from , mid - 1);
  } else
    return from;
}

int main()
{
  cin >> s >> s2;
  s = "#" + s;
  s2 = "#" + s2;

  for(int i = 1 ; i < s.size() ; i++){
    cin >> v[i];
  }
  cout << binarysearch(0 , s.size() - 1);

  return 0;
}