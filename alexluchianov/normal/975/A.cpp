#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> v;

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ;i++){
    string s;
    cin >> s;
    int seen[30] = {0};
    for(int j = 0 ;j < s.size() ;j++)
      seen[s[j] - 'a']++;
    string a;
    for(int j = 0 ;j < 26 ;j++)
      if(0 < seen[j])
        a +=  (j + 'a');
    v.push_back(a);
  }
  sort(v.begin() , v.end());
  int result = 1;
  for(int i = 1 ; i < v.size() ;i++)
    if(v[i] != v[i - 1])
      result++;
  cout << result;
  return 0;
}