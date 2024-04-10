#include <iostream>
#include <fstream>

using namespace std;
ifstream in ("friends.in");

long long  cnt1 ,cnt2 ,x ,y;
bool gift(int v){
  int s1 ,s2 ,s3;
  s1 = v/x - v/(x*y);
  s2 = v/y - v/(x*y);
  s3 = v - v/x - v/y + v/(x*y);
  //cout<<s1<<" "<<s2<<" "<<s3<<'\n';
  if(cnt1 <= s2 + s3 && cnt2 <= s1 + s3){
    return cnt1 + cnt2 <= s1 + s2 + s3;
  }else
    return 0;
}
int main()
{
  long long st = 0 ,dr = 	214740000000000;
  //cout<<dr;
  cin>>cnt1>>cnt2>>x>>y;
  int mij;

  while(st <= dr){
    if(st == dr){
      cout<<mij;
      return 0;
    }
    if(gift(mij)){
      dr = mij;
    }else{
      st = mij + 1;
    }
    mij = (st + dr)/2;
  }
  //*/
 // cout<<mij;
  return 0;
}