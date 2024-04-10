#include <cstdio>
#include <cctype>
#include <string>
#include <map>
using namespace std;

const int MAXM = 1005;
const int MAXL = 15;

int N, M;
map <string, string> f;
int cnt[MAXM][5];

string neg(string s) {
  for (int i = 0; i < M; i++)
    if (s[i] <= '1')
      s[i] = '0' + '1' - s[i];
    else
      s[i] = '2' + '3' - s[i];
  return s;
}

string operator &(string a, string b) {
  string res = "";
  for (int i = 0; i < M; i++)
    if (a[i] == '0' || b[i] == '0')
      res += '0';
    else if (a[i] == '1')
      res += b[i];
    else if (b[i] == '1')
      res += a[i];
    else if (a[i] == b[i])
      res += a[i];
    else 
      res += '0';
  return res;
}

string operator |(string a, string b) {
  return neg(neg(a) & neg(b));
}

string operator ^(string a, string b) {
  return (a & neg(b)) | (neg(a) & b);
}

string get(string s) {
  if (s == "?")
    return string(M, '2');
  return f[s];
}

void load() {
  scanf("%d%d", &N, &M);
  while (N--) {
    char name[MAXL], buff[MAXM];
    scanf("%s := %s", name, buff);
    if (isdigit(buff[0])) 
      f[name] = buff;
    else {
      char op[5], _buff[MAXM];
      scanf("%s%s", op, _buff);
      string x = get(buff);
      string y = get(_buff);
      if (op[0] == 'A')
        f[name] = x & y;
      else if (op[0] == 'O')
        f[name] = x | y;
      else
        f[name] = x ^ y;
    }
  }
}

void solve() {
  for (map <string, string> :: iterator it = f.begin(); it != f.end(); it++) 
    for (int i = 0; i < M; i++)
      cnt[i][(it -> second)[i] - '0']++;
  
  for (int i = 0; i < M; i++)
    printf("%d", cnt[i][2] < cnt[i][3]);
  puts("");
  
  for (int i = 0; i < M; i++)
    printf("%d", cnt[i][2] > cnt[i][3]);
  puts("");    
}

int main() {
  load();
  solve();
  return 0;
}