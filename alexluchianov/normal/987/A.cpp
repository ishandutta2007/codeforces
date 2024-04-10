#include <iostream>
#include <map>

using namespace std;

map < string , int > f;


int main()
{
  int n ;
  cin >> n;
  for(int i = 1 ; i <= n ;i++){
    string s;
    cin >> s;
    f[s] = 1;
  }
  cout << 6 - n << '\n';
  if(f["red"] == 0)
    cout << "Reality\n";
  if(f["purple"] == 0)
    cout << "Power\n";
  if(f["green"] == 0)
    cout << "Time\n";
  if(f["blue"] == 0)
    cout << "Space\n";
  if(f["yellow"] == 0)
    cout << "Mind\n";
  if(f["orange"] == 0)
    cout << "Soul\n";
  return 0;
}