#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
string s;
int pre[1 + nmax];
int frec[1 + nmax];

void computepre(){
  int i = 0, j = 2;
  while(j < s.size()){
    if(s[j] == s[i + 1]) {
      pre[j] = i + 1;
      j++;
      i++;
    } else if(i == 0)
      j++;
    else
      i = pre[i];
  }
  for(int i = 2; i < s.size() - 1;i++)
    frec[pre[i]]++;
}

int main()
{
  cin >> s;
  s = "#" + s;
  computepre();
  int curr = pre[s.size() - 1];
  while(0 < curr && frec[curr] == 0){
    curr = pre[curr];
  }

  if(0 < curr)
    for(int i = 1;i <= curr; i++)
      cout << s[i];
  else
    cout << "Just a legend";

  return 0;
}