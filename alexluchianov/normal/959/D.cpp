#include <iostream>

using namespace std;

int const nmax = 2000000;

int dr[5 + nmax];
int used[5 + nmax];

bool canplace(int n){
  for(int i = 2 ; i * i <= n ; i++){
    if(n % i == 0){
      if(0 < used[i])
        return 0;

      while(n % i == 0)
        n /= i;
    }
  }
  if(1 == n || 0 == used[n])
    return 1;
  else
    return 0;
}

void place(int n){
  for(int i = 2 ; i * i <= n ; i++){
    if(n % i == 0){
      used[i] = 1;
      while(n % i == 0)
        n /= i;
    }
  }
  used[n] = 1;

}

int jump(int a){
  if(a != dr[a])
    dr[a] = jump(dr[a]);
  return dr[a];
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= nmax ; i++)
    dr[i] = i;

  bool ok = 0;

  for(int i = 1 ; i <= n ; i++){
    int val;
    cin >> val;
    int start = 1;

    if(ok == 0)
      start = val;
    else
      start = 2;

    while(true){
      start = jump(start);
      dr[start] = start + 1;

      if(canplace(start) == 1) {
        place(start);
        if(val < start )
          ok = 1;
        cout << start << " ";
        break;
      }

    }
  }
  return 0;
}