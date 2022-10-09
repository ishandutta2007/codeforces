#include <iostream>

using namespace std;

int const nmax = 100000;
int mult[1 + nmax], sz[1 + nmax], edges[1 + nmax];

int jump(int a){
  if(a != mult[a])
    mult[a] = jump(mult[a]);
  return mult[a];
}

void unite(int gala, int galb){
  gala = jump(gala);
  galb = jump(galb);
  if(sz[galb] < sz[gala])
    swap(gala, galb);
  if(gala != galb) {
    sz[galb] += sz[gala];
    sz[gala] = 0;
    edges[galb] += edges[gala];
    edges[gala] = 0;
    mult[gala] = galb;
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++) {
    mult[i] = i;
    sz[i] = 1;
  }
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    unite(x, y);
    edges[jump(x)]++;
  }
  int result = 0;
  for(int i = 1;i <= n; i++){
    if(0 < sz[i] && edges[i] == sz[i] - 1)
      result++;
  }
  cout << result;
  return 0;
}