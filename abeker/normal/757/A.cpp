#include <cstdio>
using namespace std;

const int MAXN = 100005;
const char c[] = "Bulbasaur";
const char t[] = "Bulbasr";

char s[MAXN];
int cnt[MAXN];
int need[MAXN];

int main() {
  scanf("%s", s);
  for (int i = 0; s[i]; i++)
    cnt[s[i]]++;
  for (int i = 0; i < 9; i++)
    need[c[i]]++;
      
  int sol = 0;
  while (1) {
    bool ok = true;
    for (int i = 0; i < 7; i++)
      if (cnt[t[i]] < need[t[i]])
        ok = false;
    if (!ok)
      break;
    for (int i = 0; i < 7; i++)
      cnt[t[i]] -= need[t[i]];
    sol++;
  }
  
  printf("%d\n", sol);
  
  return 0;
}