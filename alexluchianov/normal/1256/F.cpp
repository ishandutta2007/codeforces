#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const sigma = 26;
int const inf = 1000000000;
char s[1 + nmax];
char s2[1 + nmax];
int frec[1 + sigma], frec2[1 + sigma];
int pos[1 + sigma], pos2[1 + sigma];

void solve(){
  int n;
  cin >> n;
  for(int i = 0;i < sigma; i++)
    frec[i] = frec2[i] = pos[i] = pos2[i] = 0;

  for(int i = 1;i <= n; i++)
    cin >> s[i];
  for(int i = 1;i <= n; i++)
    cin >> s2[i];
  for(int i = 1;i <= n; i++)
    frec[s[i] - 'a']++;
  for(int i = 1;i <= n; i++)
    frec2[s2[i] - 'a']++;
  for(int i = 0; i < sigma; i++)
    if(frec[i] != frec2[i]) {
      cout << "NO\n";
      return;
    }
  bool canstall = false;
  for(int i = 0;i < sigma; i++)
    canstall |= (1 < frec[i]);
  if(canstall == false){
    ll dist = 0;
    for(int i = 1; i <= n; i++){
      for(int j = i; j <= n; j++)
        if(s[i] == s2[j]) {
          for(int k = j - 1; i <= k; k--) {
            swap(s2[k], s2[k + 1]);
            dist++;
          }
        }
    }

    if(dist % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else
    cout << "YES\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}
/*
1
8
abcdefgh
agdbchef
*/