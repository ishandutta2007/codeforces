#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  int hh,mm,a;
  scanf("%d:%d %d",&hh,&mm,&a);

  auto inc=
    [&]()->void{
      mm++;
      if(mm>=60) mm-=60,hh++;
      if(hh>=24) hh-=24;      
    };
  
  while(a--) inc();

  printf("%02d:%02d\n",hh,mm);
  return 0;
}