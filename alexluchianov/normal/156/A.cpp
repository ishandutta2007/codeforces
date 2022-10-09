#include <iostream>

using namespace std;

#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int main()
{
  string s;
  string s2;
  cin >> s >> s2;
  string bound;
  for(int i = 0 ; i < s2.size() ; i++){
    bound += "#";
  }
  s = bound + s + bound;
  int smin = s2.size();
  for(int i = 0 ; i < s.size() - s2.size() + 1; i++){
    int sum = 0;
    for(int j = 0 ; j < s2.size() ; j++){
      if(s[i + j] != s2[j]){
        sum++;
      }
    }
    smin = MIN(smin , sum);
  }
  cout << smin;
  return 0;
}