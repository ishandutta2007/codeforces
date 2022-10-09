#include <iostream>
#include <cstdlib>

using namespace std;

int const nmax = 30;
int sign[5 + nmax];

int lim , n;

void precompute(){
  cout << lim << '\n';
  flush(cout);
  cin >> sign[1];
  if(sign[1] == 0)
    exit(0);
  for(int i = 2 ; i <= n ;i++){
    cout << lim << '\n';
    flush(cout);
    cin >> sign[i];
  }

  for(int i = 1 ; i <= n ;i++)
    sign[i] *= -1;
}


void binarysearch(int from , int to , int p ){
  if(from < to){
    int mid = (from + to) / 2 , result;

    cout << mid << '\n';
    flush(cout);
    cin >> result;
    result *= sign[(p - 1) % n + 1];
    if(result == 0)
      exit(0);
    else if(result == -1)
      binarysearch(from ,mid - 1 , p + 1);
    else
      binarysearch(mid + 1 , to , p + 1);

  } else {
    cout << from << '\n';
    flush(cout);
    int result = 0;
    cin >> result;

    exit(0);
  }
}
int main()
{
  cin >> lim >> n;
  precompute();
  binarysearch(1 , lim , 1);

  return 0;
}