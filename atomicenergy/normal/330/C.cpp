#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#define for(a,b) for(int a=0; a<b; a++)
using namespace std;


int main()
{
  int l, h;
  cin >> l;
  h=l;
  bool cake[100][100];
  int length[100];
  int height[100];

  for(a, l){
        length[a]=-1;
  }
  for(b, h){
        height[b]=-1;
  }

  char c;
  for(a, l){
        for(b, h){
            cin >> c;
            cake[a][b]=(c=='.');
            if(cake[a][b]){
                length[a]=b;
                height[b]=a;
            }
        }
  }
  bool is = true;
  for(a,l){
        if (length[a]==-1){
            is=false;
        }
  }
  if(is){
        for (a, l){
            cout << a+1 << " " << length[a]+1 << "\n";
        }
  }
  else{
  bool is = true;
  for(b,h){
        if (height[b]==-1){
            is=false;
        }
  }
  if(is){
        for (b, h){
            cout << (height[b]+1) << " " << b+1 << "\n";
        }
  }
  else{
    cout << "-1";
  }
  }
}