#include <iostream>
#include<math.h>
#include<cmath>
using namespace std;
int score(int p, int t){
    return max(((3*p)/10),(p-((p/250)*t)));
}
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int Misha = (score(a,c));
    int Vasya = (score(b,d));
    if(Misha==Vasya){
        cout<<"Tie";
    }
    else if(Misha < Vasya){
        cout<<"Vasya";
    }
    else if(Misha > Vasya){
        cout<<"Misha";
    }
    return 0;
}