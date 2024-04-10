#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int const nmax = 100000;

int aib[5 + nmax];
int n;

void update(int x , int val){
  while(x <= n){
    aib[x] += val;
    x = (x + (x ^ (x & (x - 1))));
  }
}

int query(int x){
  int sum = 0;
  while(0 < x){
    sum += aib[x];
    x = (x & (x - 1));
  }
  return sum;
}
int binsearch(int val){
  if(val < 0)
    return -1;

  int x = 0;
  for(int jump = (1 << 20) ; 0 < jump ;jump /= 2){
    if(x + jump <= n && aib[x + jump] <= val){
      val -= aib[x + jump];
      x += jump;
    }
  }
  return x;
}

int v[5 + nmax];

struct Shark{
  int x;
  int pos;
  bool operator < (Shark const &a) const{
    return x < a.x;
  }
};
Shark q[5 + nmax];

map <int , int > frec;


int main()
{
  cin >> n;
  aib[0]++;

  update(n + 1 , 1);

  for(int i = 1 ; i <= n ;i++){
    cin >> v[i];
    q[i] = {v[i] , i};
    update(i , 1);
  }
  sort(q + 1 , q + n + 1);
  int smax = 0 , soli = 0;
  int zones = 0;

  for(int i = 1 ; i <= n ;i++){
    int val = query(q[i].pos);
    int pos1 = binsearch(val - 2) + 1;
    int pos2 = binsearch(val) + 1;
    if(q[i].pos + 1 != pos2){
      frec[pos2 - q[i].pos - 1]--;
      zones--;
    } if(pos1 + 1 != q[i].pos) {
      frec[q[i].pos - pos1 - 1]--;
      zones--;
    }
    zones++;
    frec[pos2 - pos1 - 1]++;
    update(q[i].pos , -1);
    if(frec[pos2 - pos1 - 1] == zones){
      if(smax < zones){
        smax = zones;
        soli = q[i].x + 1;
      }
    }

  }
  cout << soli;
  return 0;
}