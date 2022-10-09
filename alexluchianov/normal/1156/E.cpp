#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax];
int pos[1 + nmax];
int mult[1 + nmax], sz[1 + nmax];

int jump(int a){
  if(mult[a] != a)
    mult[a] = jump(mult[a]);
  return mult[a];
}

void unite(int gala, int galb){
  gala = jump(gala);
  galb = jump(galb);
  if(sz[gala] < sz[galb]) {
    sz[galb] += sz[gala];
    sz[gala] = 0;
    mult[gala] = galb;
  } else {
    sz[gala] += sz[galb];
    sz[galb] = 0;
    mult[galb] = gala;
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    pos[v[i]] = i;
  }

  for(int i = 1;i <= n; i++) {
    mult[i] = i; sz[i] = 1;
  }

  v[0] = v[n + 1] = (1 + nmax);

  int result = 0;

  for(int i = 2;i <= n; i++){
    int p = pos[i];

    if(v[p - 1] <= v[p] && v[p + 1] <= v[p]){
      int gala = jump(p - 1), galb = jump(p + 1);

      if(sz[gala] < sz[galb]) {
        for(int j = 1; j <= sz[gala]; j++){
          int p2 = pos[i - v[p - j]];
          if(p < p2 && p2 <= p + sz[galb])
            result++;
        }
      } else {
        for(int j = 1; j <= sz[galb]; j++){
          int p2 = pos[i - v[p + j]];
          if(p - sz[gala] <= p2 && p2 < p)
            result++;
        }
      }
    }
    if(v[p - 1] <= v[p])
      unite(p - 1, p);
    if(v[p + 1] <= v[p])
      unite(p, p + 1);
  }
  cout << result;
  return 0;
}