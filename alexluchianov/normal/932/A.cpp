#include <iostream>
#include <cstring>

using namespace std;
int const nmax = 10000;
char line[5 + nmax];

int main()
{
  cin>>line;
  int n = strlen(line);
  cout<<line;
  for(int i = n - 1 ; 0 <= i ;i--){
    cout<<line[i];
  }

  return 0;
}