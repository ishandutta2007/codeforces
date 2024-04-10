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
int v2[1 + nmax];

vector<pair<int,pair<int,int> > > op;

void addmove(int x, int y, int d){
  v[x] += d;
  v[y] -= d;
  op.push_back({x, {y, d}});
}

int ind[1 + nmax];
bool compare(int x, int y){
  return v[x] < v[y];
}
int rev[1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    ind[i] = i;
  sort(ind + 1, ind + n + 1, compare);

  for(int i = 1;i <= n; i++)
    rev[i] = ind[i];

  for(int i = 1; i <= n; i++)
    cin >> v2[i];
  sort(v + 1, v + n + 1);
  sort(v2 + 1, v2 + n + 1);

  ll sum = 0;

  vector<int> st;

  for(int i = 1;i <= n; i++){
    sum += v2[i] - v[i];
    if(sum < 0) {
      cout << "NO";
      return 0;
    }

    if(0 < v2[i] - v[i])
      st.push_back(i);
    else {
      while(v2[i] < v[i]){
        int d = min((v2[st.back()] - v[st.back()]), v[i] - v2[i]);
        addmove(st.back(), i, d);
        if(v[st.back()] == v2[st.back()])
          st.pop_back();
      }
    }
  }

  for(int i = 1;i <= n; i++)
    if(v[i] != v2[i]) {
      cout << "NO";
      return 0;
    }

  cout << "YES\n";
  cout << op.size() << '\n';
  for(int i = 0; i < op.size(); i++)
    cout << ind[op[i].first] << " " << ind[op[i].second.first] << " " << op[i].second.second << '\n';

  return 0;
}