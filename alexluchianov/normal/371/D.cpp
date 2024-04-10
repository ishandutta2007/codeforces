#include <iostream>

using namespace std;

#define ll long long

int const nmax = 200000;
int cap[5 + nmax];
int a[5 + nmax];
int dr[5 + nmax];

void pour(int x, int y , int n){
  if(x <= n){
    if(a[x] + y <= cap[x])
      a[x] += y;
    else {
      y -= cap[x] - a[x];
      a[x] = cap[x];
      pour(dr[x + 1] , y , n);
      dr[x] = dr[x + 1];
    }
  } else
    return ;
}
int main()
{
  int n , m;
  cin >> n;
  for(int i = 1 ; i <= n ; i++) {
    cin >> cap[i];
    dr[i] = i;
  }
  dr[n + 1] = n + 1;

  cin >> m;
  for(int i = 1 ; i <= m ; i++){
    int op;
    cin >> op;
    if(op == 1){
      int x , y;
      cin >> x >> y;
      pour(x , y , n);
    } else {
      int x;
      cin >> x;
      cout << a[x] << '\n';
    }
  }
  return 0;
}