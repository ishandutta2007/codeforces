#include <iostream>

using namespace std;

int main()
{
  string s;

  int n , k , a , b;
  cin >> n >> k >> a >> b;
  int last = -1 ;
  int scount = 0;

  for(int i = 1 ; i <= n ; i++){
    if(scount == k){
      if(last == 1){
        s += "B";
        scount = 1;
        last = 2;

        b--;
      } else {
        s += "G";
        scount = 1;
        last = 1;
        a--;
      }
    } else {
      if(a < b){
        s += "B";

        if(last == 2)
          scount++;
        else
          scount = 1;

        last = 2;
        b--;
      } else {
        s += "G";

        if(last == 1)
          scount++;
        else
          scount = 1;

        last = 1;
        a--;
      }
    }
  }
  if(a < 0 || b < 0)
    cout << "NO";
  else
    cout << s;
  return 0;
}