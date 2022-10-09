#include <iostream>

using namespace std;

int const nmax = 100;
int frec[5 + nmax];
int v[5 + nmax];
int seen[5 + nmax];

void erasep(int color){
  frec[color]--;
  for(int i = 1 ; i <= nmax ; i++){
    if(v[i] == color && seen[i] == 0) {
      seen[i] = 1;
      return;
    }
  }
}
int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++){
    cin >> v[i];
    frec[v[i]]++;
  }
  int balance = 0;
  for(int i = 1 ; i <= nmax ; i++){
    if(frec[i] == 1)
      balance++;
  }
  while(1 < balance){
    for(int i = 1 ; i <= nmax ; i++){
      if(frec[i] == 1) {
        erasep(i);
        balance -= 2;
        break;
      }
    }
  }
  if(balance == 0){
    cout << "YES\n";
    for(int i = 1 ; i <= n ; i++){
      if(seen[i] == 0)
        cout << "A";
      else
        cout << "B";
    }
  } else {
    bool ok = 0;
    for(int i = 1 ; i <= nmax ; i++){
      if(frec[i] >= 3){
        erasep(i);
        balance--;
        break;
      }
    }
    if(balance == 0){
      cout << "YES\n";
      for(int i = 1 ; i <= n ; i++){
        if(seen[i] == 0)
          cout << "A";
        else
          cout << "B";
      }
    } else
      cout << "NO\n";
  }
  return 0;
}