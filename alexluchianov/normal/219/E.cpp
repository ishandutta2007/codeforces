#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const mil = 1000000;

int v[1 + nmax];
int st[1 + nmax], dr[1 + nmax];
int n, m;

int getdist(int x, int y){
  if(x == 1 && y == n)
    return n + 1;

  if(x == 1)
    return y;
  else if(y == n)
    return n - x + 1;
  else
    return (y - x) / 2 + 1;
}

struct Interval{
  int x;
  int y;
  bool operator < (Interval const &a) const{
    if(getdist(x, y) != getdist(a.x, a.y))
      return getdist(x, y) < getdist(a.x, a.y);
    else
      return x > a.x;
  }
};

int pos[1 + mil];

int getmiddle(int x, int y){
  if(x == 1)
    return 1;
  else if(y == n)
    return n;
  else
    return (y + x) / 2;
}

int main()
{
  cin >> n >> m;
  priority_queue<Interval> pq;

  pq.push({1, n});
  v[0] = v[n + 1] = 1;

  dr[0] = n + 1;
  st[n + 1] = 0;

  for(int i = 1; i <= m; i++){
    int op, id;
    cin >> op >> id;
    if(op == 1){
      while(true){
        Interval var = pq.top();
        pq.pop();
        if(v[var.y + 1] == 1 && v[var.x - 1] == 1 && dr[var.x - 1] == (var.y + 1) ){
          int mid = getmiddle(var.x, var.y);
          dr[var.x - 1] = mid;
          st[var.y + 1] = mid;
          st[mid] = var.x - 1;
          dr[mid] = var.y + 1;

          if(var.x <= mid - 1)
            pq.push({var.x, mid - 1});
          if(mid + 1 <= var.y)
            pq.push({mid + 1, var.y});

          v[mid] = 1;
          pos[id] = mid;
          cout << mid << '\n';
          break;
        }
      }

    } else {
      int mid = pos[id];
      v[mid] = 0;
      int pos1 = st[mid], pos2 = dr[mid];
      dr[pos1] = pos2;
      st[pos2] = pos1;
      pq.push({pos1 + 1, pos2 - 1});
    }

  }
  return 0;
}