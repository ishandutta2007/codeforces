#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 250000;
int const modulo1 = 1000000007;
int const modulo2 = 1000000009;
int const modulo3 = 1000000021;

struct Hash{
  int hash1;
  int hash2;
  int hash3;
  Hash (int val = 0){
    hash1 = hash2 = hash3 = val;
  }
  Hash(int hash1, int hash2, int hash3){
    this->hash1 = hash1;
    this->hash2 = hash2;
    this->hash3 = hash3;
  }
  Hash operator * (Hash const &a) const{
    return {(1LL * hash1 * a.hash1) % modulo1, (1LL * hash2 * a.hash2) % modulo2, (1LL * hash3 * a.hash3) % modulo3 };
  }
  Hash operator + (Hash const &a) const{
    return {(hash1 + a.hash1) % modulo1, (hash2 + a.hash2) % modulo2,  (hash3 + a.hash3) % modulo3 };
  }
  bool operator == (Hash const &a) const{
    return hash1 == a.hash1 && hash2 == a.hash2 && hash3 == a.hash3;
  }
};
Hash intersect[1 + nmax], intersect2[1 + nmax];
Hash pow2[1 + nmax];

struct Seg{
  int x;
  int y;
  int id;
};
bool sortbyx(Seg a, Seg b){
  return a.x < b.x;
}
bool sortbyy(Seg a, Seg b){
  return a.y < b.y;
}
Seg v[1 + nmax], v2[1 + nmax];
Seg v3[1 + nmax], v4[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  pow2[0] = 1;
  for(int i = 1;i <= n; i++)
    pow2[i] = pow2[i - 1] * 2;

  for(int i = 1;i <= n; i++){
    v[i].id = i;
    cin >> v[i].x >> v[i].y;
    cin >> v2[i].x >> v2[i].y;
    v2[i].id = i;
    v3[i] = v[i];
    v4[i] = v2[i];
  }
  sort(v + 1, v + n + 1, sortbyx);
  sort(v3 + 1, v3 + n + 1, sortbyy);
  int ptr = 1;
  Hash pref = 0;
  for(int i = 1;i <= n; i++){
    while(ptr <= n && v3[ptr].y < v[i].x){
      pref = pref + pow2[v3[ptr].id];
      ptr++;
    }
    intersect[v[i].id] = intersect[v[i].id] + pref;
  }
  ptr = n;
  Hash suff = 0;
  for(int i = n; 1 <= i; i--){
    while(1 <= ptr && v3[i].y < v[ptr].x){
      suff = suff + pow2[v[ptr].id];
      ptr--;
    }
    intersect[v3[i].id] = intersect[v3[i].id] + suff;
  }
  sort(v2 + 1, v2 + n + 1, sortbyx);
  sort(v4 + 1, v4 + n + 1, sortbyy);

  ptr = 1;
  pref = 0;
  for(int i = 1;i <= n; i++){
    while(ptr <= n && v4[ptr].y < v2[i].x){
      pref = pref + pow2[v4[ptr].id];
      ptr++;
    }
    intersect2[v2[i].id] = intersect2[v2[i].id] + pref;
  }
  ptr = n;
  suff = 0;
  for(int i = n; 1 <= i; i--){
    while(1 <= ptr && v4[i].y < v2[ptr].x){
      suff = suff + pow2[v2[ptr].id];
      ptr--;
    }
    intersect2[v4[i].id] = intersect2[v4[i].id] + suff;
  }

  for(int i = 1;i <= n; i++){
    if(!(intersect[i] == intersect2[i])) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}