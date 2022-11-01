#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

const int N = 300010;

int n, one, two;
vector <int> a, b;
pair <int, int> p[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &p[i].x, &p[i].y);
    if (p[i].x < p[i].y) ++one, a.emplace_back(i);
    else ++two, b.emplace_back(i);
  }
  if (one > two) {
    sort(a.begin(), a.end(), [] (int i, int j) {return p[i].y > p[j].y;});
  } else {
    swap(one, two), swap(a, b);
    sort(a.begin(), a.end(), [] (int i, int j) {return p[i].y < p[j].y;});
  }
  cout << one << '\n';
  for (int it : a) printf("%d ", it);
  puts("");
  return 0;
}