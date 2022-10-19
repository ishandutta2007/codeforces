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
  cin >> l >> h;
  bool cake[10][10];
  bool length[10];
  bool height[10];

  for(a, l){
        length[a]=0;
  }
  for(b, h){
        height[b]=0;
  }

  char c;
  for(a, l){
        for(b, h){
            cin >> c;
            cake[a][b]=(c=='S');
            length[a] = length[a] || cake[a][b];
            height[b] = height [b] || cake[a][b];
        }
  }
  int total=0;
  int sum=0;
  for(a, l){

    if (length[a]){
        total++;
    }
}

for(b, h){

    if (height[b]){
        sum++;
    }
}

    cout << l*h-sum*total;

}