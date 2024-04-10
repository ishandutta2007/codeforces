// Example program
#include <iostream>
#include <string>

using namespace std;
int main() {
  int i=0;
  int a=-200;
  string line;
  cin >> line;
  while (i<line.length()){
      if(line[i]=='1'){
          if(a<0){
              a=0;
          }
      }
      else if(line[i]=='0'){
          a++;
          if(a==6){
              cout << "yes" << endl;
              return 0;
          }
      }
      i++;
  }
    cout << "no" << endl;
}