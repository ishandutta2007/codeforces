#include <iostream>

using namespace std;

int const inf = 1000000000;

#define MAX(a , b) (((a) < (b)) ? (b) : (a))
#define MIN(a , b) (((a) < (b)) ? (a) : (b))

int smax = 0;
int smin = inf;

void binarysearch(int from , int to , int step , int p){
  //cout << '\n' << step << " " << from << " " << to << '\n';

  if(step == 0){

    //cout << smax << " " << smin << '\n';

    if(from <= to)
      cout << 0 << " "  << 0 << " " << inf << " " << from;
    else if(smin + 1 <= inf)
      cout << 0 << " " << smin + 1 << " " << inf - 1 << " " << smin;
    else
      cout << 0 << " " << smax - 1 << " " << inf - 1 << " " << smax;

    cout << '\n';

    cout << flush;

  } else {

    int mid = (from + to) >> 1;

    cout << inf << " " << mid << '\n';

    cout << flush;

    string s;

    cin >> s;
    cout << flush;

    //s = "black";

    if( (s == "white" && p == 1) || (s == "black" && p == 0) ){
      smin = MIN(smin , mid);
      binarysearch(from , mid - 1 , step - 1 , p);
    } else {
      smax = MAX(smax , mid);
      binarysearch(mid + 1 , to , step - 1 , p);
    }
  }
}
int main()
{
  int n;
  cin >> n;
  cout << flush;

  cout << inf << " " << inf << '\n';
  cout << flush;

  string s;
  cin >> s;
  cout << flush;

  //s = "black";

  if(s == "white")
    binarysearch(0 , inf - 1, n - 1, 1);
  else
    binarysearch(0 , inf - 1 , n - 1, 0);

  return 0;
}