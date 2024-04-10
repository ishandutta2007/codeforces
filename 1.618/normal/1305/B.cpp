#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 1005
using namespace std;
typedef long long ll;

char s[maxn];
int n;
vector<int> pos;
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int i = 1, j = n;
  while (i <= j) {
    while (s[i] == ')') i++;
    while (s[j] == '(') j--;
    
//    cout << i << " " << j << endl;
//    system("pause");
    
    if (i > j) break;
    pos.push_back(i);
    pos.push_back(j);
    
//    cout << i << " " << j << endl;
    
    i++, j--;
  }
  if (pos.empty()) {
    puts("0");
  } else {
    puts("1");
    sort(pos.begin(), pos.end());
    printf("%d\n", (int)pos.size());
    for (int i = 0; i < (int)pos.size(); i++) {
      printf("%d%c", pos[i], i == (int)pos.size() - 1 ? '\n' : ' ');
    }
  }
  return 0;
}