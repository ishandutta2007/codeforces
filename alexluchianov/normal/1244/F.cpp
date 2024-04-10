#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int const nmax = 200000;
char v[1 + nmax];
ll ring;

int st(int x){
  return (ring + x - 1) % ring;
}
int dr(int x){
  return (x + 1) % ring;
}

char chr(char a){
  if(a % 2 == 0)
    return 'W';
  else
    return 'B';
}

int dist[1 + nmax];
int dist2[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, k;
  cin >> n >> k;
  ring = n;
  for(int i = 0;i < n; i++) {
    cin >> v[i];
    if(v[i] == 'W')
      v[i] = 0;
    else
      v[i] = 1;
  }
  for(int i = 0; i < n; i++)
    dist[i] = dist2[i] = nmax;

  for(int i = 0; i < n; i++)
    if(v[st(i)] == v[i] || v[i] == v[dr(i)] )
      dist[i] = dist2[i] = 0;

  for(int i = 0; i < n; i++)
    dist[i] = min(dist[i], dist[st(i)] + 1);
  for(int i = 0; i < n; i++)
    dist[i] = min(dist[i], dist[st(i)] + 1);

  for(int i = n - 1;0 <= i; i--)
    dist2[i] = min(dist2[i], dist2[dr(i)] + 1);
  for(int i = n - 1;0 <= i; i--)
    dist2[i] = min(dist2[i], dist2[dr(i)] + 1);

  for(int i = 0; i < n; i++){
    int overvall = min(dist[i], dist2[i]);
    if(overvall == nmax || k <= overvall)
      cout << chr(v[i] + k);
    else
      cout << chr(v[i] + overvall);
  }

  return 0;
}