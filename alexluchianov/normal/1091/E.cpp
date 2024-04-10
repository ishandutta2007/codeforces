#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 1200000;
int v[5 + nmax];
int v2[5 + nmax];
ll sum[5 + nmax];
int frec[5 + nmax];

void cleararr(int *arr , int n){
  for(int i = 0 ; i <= n ; i++)
    arr[i] = 0;
}
void cleararr(ll *arr , int n){
  for(int i = 0 ; i <= n ; i++)
    arr[i] = 0;
}

bool solve(int n , int whattoadd , int scount){
  int vp2 = 0;
  int vp = 0;
  while(vp < n || 0 < scount){
    if(scount == 0)
      v2[++vp2] = v[++vp];
    else if(vp == n) {
      v2[++vp2] = whattoadd;
      scount--;
    } else if(v[vp + 1] <= whattoadd){
      v2[++vp2] = whattoadd;
      scount--;
    } else
      v2[++vp2] = v[++vp];
  }
  cleararr(sum , vp2);
  cleararr(frec , vp2);

  for(int i = 1 ; i <= vp2 ; i++)
    sum[i] = sum[i - 1] + v2[i];

  ll result = 0 , acc = 0;

  for(int i = vp2 ; 1 <= i ; i--){

    if(sum[i] <= 1LL * i * (i - 1) + result){
      acc += frec[i];
      result -= acc;
      frec[v2[i]]++;
      if(i <= v2[i])
        acc++;

      result += min(v2[i] , i - 1);
    } else
      return 0;
  }
  return 1;

}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  sort(v + 1 , v + n + 1);
  reverse(v + 1 , v + n + 1);
  ll sum = 0;
  for(int i = 1 ; i <= n ; i++)
    sum += v[i];

  int sadd = 0;
  if((sum + n) % 2 == 0)
    sadd = n;
  else
    sadd = n - 1;

  if(solve(n , 1 , sadd) == 0){
    cout << -1;
  } else {
    int x = 0;
    for(int jump = (1 << 18) ; 1 < jump ; jump /= 2){
      if(x + jump <= sadd){
        if(solve(n , 1 , sadd - jump - x) == 1)
          x += jump;
      }
    }
    sadd -= x;


    if(solve(n , sadd , 1) == 0){

      cout << -1;
    } else {
      x = 0;
      for(int jump = (1 << 18) ; 1 < jump ; jump /= 2){
        if(solve(n , sadd + x + jump , 1) == 1)
          x += jump;
      }
      for(int i = 0 ; i <= x ; i += 2){
        cout << sadd + i << " " ;
      }
    }
  }

  return 0;
}