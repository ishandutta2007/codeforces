#include <bits/stdc++.h>

using namespace std;

const int N_ = 3050;

int N, P, S;

struct student {
  int a, b, i;
  bool operator< (const student &s) const {
    return b - a < s.b - s.a;
  }
};

vector<int> ans[2];
student students[N_];

int tb[N_][N_];
int rev[N_][N_];

int main() {
  scanf("%d%d%d", &N, &P, &S);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &students[i].a);
  }
  for(int i = 1; i <= N; i++) {
    students[i].i = i;
    scanf("%d", &students[i].b);
  }
  sort(students+1, students+N+1);

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= P+S; j++) {
      tb[i][j] = tb[i-1][j];
      
      int cur = tb[i-1][j-1] + (j <= P ? students[i].a : students[i].b);
      if(cur > tb[i][j]) {
        tb[i][j] = cur;
        rev[i][j] = -1;
      }
    }
  }

  printf("%d\n", tb[N][P+S]);
  
  for(int i = N, j = P+S; i > 0; i--) {
    if(rev[i][j] == -1) {
      ans[j > P].push_back(students[i].i);
      j--;
    }
  }

  assert(ans[0].size() == P);
  assert(ans[1].size() == S);
  for(int i = 0; i < 2; i++) {
    for(int x : ans[i]) printf("%d ", x);
    puts("");
  }
  return 0;
}