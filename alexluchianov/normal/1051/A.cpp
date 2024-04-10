#include <iostream>

using namespace std;

int main()
{
  int t;
  cin >> t;
  for(int testcase = 1 ;testcase <= t ; testcase++){
    string s;
    cin >> s;
    int okalp = 0;
    int okalp2 = 0;
    int oknum = 0;
    for(int i = 0 ; i < s.size() ; i++){
      if('a' <= s[i] && s[i] <= 'z')
        okalp++;
      else if('0' <= s[i] && s[i] <= '9')
        oknum++;
      else if('A' <= s[i] && s[i] <= 'Z')
        okalp2++;
    }
    if((okalp == 0) + (okalp2 == 0) + (oknum == 0) == 1){
      for(int i = 0 ; i < s.size() ; i++){
        if('a' <= s[i] && s[i] <= 'z' && 1 < okalp){
          if(okalp2 == 0){
            s[i] = 'A';
            okalp2++;
          } else if(oknum == 0){
            s[i] = '0';
            oknum++;
          }
        } else if('A' <= s[i] && s[i] <= 'Z' && 1 < okalp2){
          if(okalp == 0){
            s[i] = 'a';
            okalp++;
          } else if(oknum == 0){
            s[i] = '0';
            oknum++;
          }
        } else if('0' <= s[i] && s[i] <= '9' && 1 < oknum){
          if(okalp2 == 0){
            s[i] = 'A';
            okalp2++;
          } else if(okalp == 0){
            s[i] = 'a';
            okalp++;
          }
        }
      }
    } else if((okalp == 0) + (okalp2 == 0) + (oknum == 0) == 2){
      if(0 < oknum) {
        s[0] = 'a';
        s[1] = 'A';
      } else if(0 < okalp){
        s[0] = 'A';
        s[1] = '0';
      } else if(0 < okalp2){
        s[0] = 'a';
        s[1] = '0';
      }
    }
    cout << s << '\n';
  }
  return 0;
}