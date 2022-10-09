#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    int n ,i ,j ,x1 ,x2 ,y1 ,y2 ,bestx1 = 31410,bestx2 = -1 ,besty1 = 31410,besty2 = -1,s = 0;
    cin>>n;
    for(i = 0 ;i < n;i++){
      cin>>x1>>y1>>x2>>y2;
      if(x1 < bestx1)
        bestx1 = x1;
      if(y1 < besty1)
        besty1 = y1;
      if(bestx2 < x2)
        bestx2 = x2;
      if(besty2 < y2)
        besty2 = y2;
      s+=fabs(x1 - x2)* fabs(y1 - y2);
    }
    if(fabs(bestx1 - bestx2) == fabs(besty1 - besty2) &&  fabs(bestx1 - bestx2) * fabs(besty1 - besty2) == s)
      cout<<"YES";
    else
      cout<<"NO";
    return 0;
}