#include <iostream>

using namespace std;

#define MIN(a , b) (((a) < (b)) ? (a) : (b))

int const nmax = 500000;
string v[5 + nmax];
int same[5 + nmax];

void computesame(int n){
  for(int i = 1 ; i < n ; i++){
    while(same[i] < v[i].size() - 1 && same[i] < v[i + 1].size() - 1){
      if(v[i][same[i] + 1] == v[i + 1][same[i] + 1])
        same[i]++;
      else
        break;
    }
  }
}
int l[5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++){
    cin >> v[i];
    v[i] = "#" + v[i];

    l[i] = v[i].size() - 1;
    v[i][l[i] + 1] = ' ';
  }
  computesame(n);
  int moves = 0;
  for(int i = n - 1 ; 1 <= i ; i--){
    while(true){
      same[i] = MIN(same[i] , MIN(l[i] , l[i + 1]));
      //cout << i << " " << same[i] << " " <<v[i][same[i] + 1] << " " <<  v[i + 1][same[i] + 1] <<  '\n';
      if(v[i][same[i] + 1] <= v[i + 1][same[i] + 1]  ){
        break;
      }

      l[i]--;
      v[i][l[i] + 1] = ' ';
      moves++;
    }
  }
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= l[i] ; j++)
      cout << v[i][j];
    cout << '\n';
  }
  return 0;
}