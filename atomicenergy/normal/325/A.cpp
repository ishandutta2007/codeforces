#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct boxes {
  int xs;
  int ys;
  int xf;
  int yf;
} boxes[5];

int main()
{
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <string.h>
    #include <cmath>
    #include <vector>
    #include <algorithm>
    int n, bottom=31400, top=0, left=31400, right=0;
    cin >> n;
    for (int a=0; a<n; a++){
        cin >> boxes[a].xs>> boxes[a].ys>> boxes[a].xf>> boxes[a].yf;
        if(boxes[a].xs<left) left=boxes[a].xs;
        if(boxes[a].xf>right) right=boxes[a].xf;
        if(boxes[a].yf>top) top=boxes[a].yf;
        if(boxes[a].ys<bottom) bottom=boxes[a].ys;
    }
    if(top-bottom!=right-left){
        cout << "NO";
    }
    else{
        int area=(top-bottom)*(top-bottom);
        for (int a=0; a<n; a++){
            area-=(boxes[a].xf-boxes[a].xs)*(boxes[a].yf-boxes[a].ys);
        }
        if(area==0){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
    }
    return 0;
}