#include <iostream>

using namespace std;

int const nmax = 100000;
int seen[5 + nmax];
int used[5 + nmax];

void update(int n , int val){
  seen[n] = (0 < val);
  for(int i = 2 ; i * i <= n ; i++){
    while(n % i == 0){
      used[i] = val;
      n /= i;
    }
  }
  if(1 < n)
    used[n] = val;
}

int check(int n){
  for(int i = 2 ; i * i <= n ; i++){
    if(n % i == 0)
      if(0 < used[i])
        return used[i];
    while(n % i == 0){
      n /= i;
    }
  }

  if(1 < n && 0 < used[n])
    return used[n];
  return 0;
}

int main()
{
  int n , m;
  cin >> n >> m;
  for(int i = 1 ; i <= m ; i++){
    char op;
    int x;
    cin >> op >> x;
    if(op == '+'){
      if(0 < seen[x]){
        cout << "Already on\n";
      } else {
        if(check(x) == 0){
          update(x , x);
          cout << "Success\n";
        } else {
          cout << "Conflict with " << check(x) << '\n';
        }
      }
    } else {
      if(0 == seen[x])
        cout << "Already off\n";
      else {
        update(x , 0);
        cout << "Success\n";
      }
    }
  }
  return 0;
}