#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int c[5 + nmax];
int x[5 + nmax];
int seen[5 + nmax];

ll totalcost = 0;

void updatecost(int node){
  int costmin = c[node];
  int target = node;
  while(x[node] != target){
    node = x[node];
    costmin = MIN(costmin , c[node]);
  }
  totalcost += costmin;
}

void update(int node , int p){
  if(seen[node] == 0){
    seen[node] = p;
    update(x[node] , p);
  } else if(seen[node] != p)
    return ;
    else
      updatecost(node);
}
int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
    cin >> c[i];
  for(int i = 1 ; i <= n ; i++)
    cin >> x[i];
  int p = 1;

  for(int i = 1 ; i <= n ; i++){
    if(seen[i] == 0){
      update(i , p);
      p++;
    }
  }
  cout << totalcost << '\n';

  return 0;
}