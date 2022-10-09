#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const namx = 1000;
int const inf = 1000000000;

int main()
{
  int n , l , smoke;
  cin >> n >> l >> smoke;

  int last = 0;

  int result = 0;

  for(int i = 1 ; i <= n ;i++){

    int start , end;
    cin >> start >> end;
    result += (start - last) / smoke;
    end += start;
    last = end;
  }
  result += (l  - last) / smoke;
  cout << result << '\n';

  return 0;
}