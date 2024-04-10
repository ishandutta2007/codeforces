#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int const nmax = 500000;
int v[1 + nmax];
int v2[1 + nmax];
int frec[1 + nmax], frec2[1 + nmax];
int dr[1 + nmax];

int Nonzero = 0;

void addset(int pos){
  frec[v[pos]]--;
  if(0 == frec[v[pos]])
    Nonzero--;
}

void deleteset(int pos){
  frec[v[pos]]++;
  if(1 == frec[v[pos]])
    Nonzero++;
}

int howmany(int from, int to, int slices, int psize, int n){
  int left = ((from - 1) / psize) * psize;
  int lend = max(left + psize,to);
  int right = n - ((n - lend) / psize) * psize + 1;
  return left / psize + 1 + (n - right + 1) / psize;
}
void solve(int from, int to, int slices, int psize, int n){
  vector<int> sol;
  int left = ((from - 1) / psize) * psize;
  int lend = max(left + psize,to);
  int right = n - ((n - lend) / psize) * psize + 1;
  while(slices < left / psize + 1 + (n - right + 1) / psize){
    if(0 < left)
      left -= psize;
    else if(right <= n)
      right += psize;
  }

  for(int i = left + 1; i < from; i++)
    sol.push_back(i);
  for(int i = lend + 1;i < right; i++)
    sol.push_back(i);

  int todelete = (lend - from + 1) - psize;

  for(int i = from; i <= lend; i++){
    if(0 < frec2[v[i]]){
      frec2[v[i]]--;
    } else if(0 < todelete) {
      sol.push_back(i);
      todelete--;
    }
  }
  cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i] << " ";
  cout << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k, m, s;
  cin >> n >> k >> m >> s;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= s; i++) {
    cin >> v2[i];
    frec[v2[i]]++;
    frec2[v2[i]]++;
    if(frec[v2[i]] == 1)
      Nonzero++;
  }

  addset(0);
  int pos = 0;
  for(int i = 1;i <= n; i++){
    deleteset(i - 1);
    while(0 < Nonzero && pos < n){
      pos++;
      addset(pos);
    }
    if(Nonzero == 0)
      dr[i] = pos;
    else
      dr[i] = n + 1;
  }

  for(int i = 1;i <= n; i++){
    if(dr[i] <= n && m <= howmany(i, dr[i], m, k, n)){
      solve(i, dr[i], m, k, n);
      return 0;
    }
  }
  cout << -1;
  return 0;
}