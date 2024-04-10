#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 1e5 + 7;
char s[MAXN];

int main()
{
  scanf(" %s", s);
  vector <char> t;
  for (int i = 0; s[i]; i++)
  {
    if (t.size() && s[i] == t.back()) t.pop_back();
    else t.push_back(s[i]);
  }
  puts(t.size() ? "NO" : "YES");
}