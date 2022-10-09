#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;

struct Player{
  ll x;
  ll y;
  int id;
  bool operator < (Player const &a) const {
    return x - y < a.x - a.y;
  }
};

Player v[5 + nmax];

ll sol[5 + nmax];

ll sumx[5 + nmax];
ll sumy[5 + nmax];

ll valpair(Player a , Player b){
  return MIN(a.x + b.y , a.y + b.x);
}


Player archive[5 + nmax];


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n , m;
  cin >> n >> m;

  for(int i = 1 ; i <= n ; i++){
    cin >> v[i].x >> v[i].y;
    v[i].id = i;
    archive[i] = v[i];
  }
  sort(v + 1 , v + n + 1);

  for(int i = 1 ; i <= n ; i++)
    sumx[i] = sumx[i - 1] + v[i].x;
  for(int i = 1 ; i <= n ; i++)
    sumy[i] = sumy[i - 1] + v[i].y;

  for(int i = 1 ; i <= n ; i++){
    sol[v[i].id] += 1LL * (i - 1) * v[i].y + sumx[i - 1];
    sol[v[i].id] += 1LL * (n - i) * v[i].x + sumy[n] - sumy[i];
  }

  for(int i = 1 ; i <= m ; i++){
    int x , y;
    cin >> x >> y;
    sol[x] -= valpair(archive[x] , archive[y]);
    sol[y] -= valpair(archive[x] , archive[y]);
  }

  for(int i = 1 ; i <= n ; i++)
    cout << sol[i] << " ";

  return 0;

}