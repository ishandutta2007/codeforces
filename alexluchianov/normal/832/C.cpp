#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;
ifstream in ("strange.in");
ofstream out ("strange.out");
struct man{
  int x;
  double speed;
  int dir;
  bool operator < (man a) const {
    return x < a.x;
  }
};
int const domain = 1000000;
int const nmax = 100000;
int n ;
double s;///number of people,ray's speed

man v[1 + nmax];

double precision = 0.0000001;
bool test(double t){
  bool okl[1 + domain] = {0};
  bool okr[1 + domain] = {0};
  for(int i = 1 ; i <= n ;i++){
    if(v[i].dir == 1){
      if(v[i].x / v[i].speed <= t){
        for(int i = 1 ; i <= domain ;i++){
          okl[i] = 1;
        }
        //cout<<":"<<t<<'\n';
        break;
      }
    }
  }
  for(int i = 1 ; i <= n ;i++){
    if(v[i].dir == 2){
      if((domain - v[i].x) / v[i].speed <= t){
        for(int i = 1 ; i <= domain ;i++){
          okr[i] = 1;
        }
        //cout<<"|"<<t<<'\n';
        break;
      }
    }
  }
  int pos = 1;
  int vp = 1;

  while(vp <= n && v[vp].dir == 2){
    vp++;
  }
  //cout<<v[vp].x<<'\n';
  while(pos <= domain && vp <= n){
    if(v[vp].x <= pos){
      int dist = pos - v[vp].x;
      double time = dist / (s - v[vp].speed);
      double pos2 = v[vp].x - time * v[vp].speed;
      if(pos2 / (s + v[vp].speed)  + time <= t){
        okl[pos] = 1;
       // cout<<pos<<'\n';
        pos++;
      } else{
        vp++;
      }
    } else{
      pos++;
    }
    while(vp <= n && v[vp].dir == 2){
      vp++;
    }
  }
  pos = domain - 1;
  vp = n;
  while(1 <= vp && v[vp].dir == 1){
    vp--;
  }
  while(1 <= pos && 1 <= n){
    if(pos <= v[vp].x ){
      int dist = v[vp].x - pos;
      double time = dist / (s - v[vp].speed);
      double pos2 = v[vp].x + time * v[vp].speed;
      if(pos2 < domain && (domain - pos2) / (s + v[vp].speed) + time <= t){
        okr[pos] = 1;
        //cout<<pos<<" "<<time<<" "<<pos2<<" "<< (domain - pos2) / (s + v[vp].speed)<<'\n';

        pos--;
      } else{
        vp--;
      }
    } else{
      pos--;
    }
    while(1 <= vp && v[vp].dir == 1){
      vp--;
    }
  }
  for(int i = 1 ; i <= domain ;i++){
    if(okl[i] == 1 && okr[i] == 1){
      //cout<<i<<'\n';
      return 1;
    }
  }
  return 0;
}
double binarysearch(double from , double to){
  if(from + precision < to){
    double mid = (from + to) / 2;
    if(test(mid) == 0){
      //cout<<":";
      return binarysearch(mid + precision , to);
    } else{
      //cout<<"|";
      return binarysearch(from ,mid);
    }
  } else
    return from;
}
int main()
{
  cin>>n>>s;
  for(int i = 1 ; i <= n ;i++){
    cin>>v[i].x>>v[i].speed>>v[i].dir;
    //cout<<v[i].x<<" "<<v[i].speed<<" "<<v[i].dir<<'\n';
  }
  //cout<<'\n';
  sort(v + 1 ,v + n + 1);
  cout<<setprecision(7)<<fixed<<binarysearch(precision , domain);
  //test(300);

  return 0;
}