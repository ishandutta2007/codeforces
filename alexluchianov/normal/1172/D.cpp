#include <iostream>
#include <vector>

using namespace std;

int const nmax = 200000;
int r[1 + nmax];
int c[1 + nmax];

struct Sol{
  int a, b, c, d;
};
vector<Sol> sol;

void solve(int from, int to){
  if(from < to){
    if(r[from] == from && c[from] == from)
      solve(from + 1, to);
    else {
      int posc = 0, posr = 0;

      for(int i = from; i <= to; i++)
        if(r[i] == from)
          posr = i;
      for(int i = from; i <= to; i++)
        if(c[i] == from)
          posc = i;

      swap(r[from], r[posr]);
      swap(c[from], c[posc]);

      sol.push_back({posr, from, from, posc});
      solve(from + 1, to);
    }
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> r[i];
  for(int i = 1; i <= n; i++)
    cin >> c[i];
  solve(1, n);

  cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i].a << " " << sol[i].b << " " << sol[i].c << " " << sol[i].d << '\n';

  return 0;
}