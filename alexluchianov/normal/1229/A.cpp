#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 7000;
ll v[1 + nmax], val[1 + nmax];
int seen[1 + nmax];
map<ll,int> frec;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;
  ll result = 0;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    cin >> val[i];

  for(int i = 1;i <= n; i++){
    frec[v[i]]++;
    if(frec[v[i]] == 2){
      for(int j = 1;j <= n; j++) {
        if((v[i] & v[j]) == v[j]) {
          if(seen[j] == 0)
            result += val[j];
          seen[j] = 1;
        }
      }
    }
  }
  cout << result;
  return 0;
}