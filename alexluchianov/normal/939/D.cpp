#include <iostream>
#include <vector>

using namespace std;

int const nmax = 100000;

string s , s2;

int x[5 + nmax];

int jump(int a){
  if(a != x[a])
    x[a] = jump(x[a]);
  return x[a];
}

void unite(int gala , int galb){
  x[jump(galb)] = jump(gala);
}

vector<pair<char , char>> v;

int main()
{
  int n;
  for(int i = 0 ; i < 26 ; i++)
    x[i] = i;
  cin >> n ;
  cin >> s;
  cin >> s2;
  for(int i = 0 ; i < n ; i++){
    if(s[i] != s2[i])
      if(jump(s[i] - 'a') != jump(s2[i] - 'a')){
        unite(s[i] - 'a' , s2[i] - 'a');
        v.push_back({s[i], s2[i]});
      }
  }
  cout << v.size() << '\n';
  for(int i = 0 ; i < v.size() ; i++)
    cout << (char)v[i].first << " " << (char)v[i].second << '\n';

  return 0;
}