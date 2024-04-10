#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int v[1 + nmax];
int a[1 + nmax];
int b[1 + nmax];

bool compare(int x, int y){
  return a[x] < a[y];
}
int main()
{
  int n;
  cin >> n;
  vector<int> sol1, sol2;
  for(int i = 1;i <= n ; i++) {
    cin >> a[i] >> b[i];
    if(a[i] < b[i])
      sol1.push_back(i);
    else
      sol2.push_back(i);
  }

  sort(sol1.begin(), sol1.end(), compare);
  reverse(sol1.begin(), sol1.end());
  sort(sol2.begin(), sol2.end(), compare);

  if(sol1.size() < sol2.size()){
    cout << sol2.size() << '\n';
    for(int i = 0; i < sol2.size(); i++)
      cout << sol2[i] << " ";
    cout << '\n';
  } else {
    cout << sol1.size() << '\n';
    for(int i = 0; i < sol1.size(); i++)
      cout << sol1[i] << " ";
    cout << '\n';
  }
  return 0;
}