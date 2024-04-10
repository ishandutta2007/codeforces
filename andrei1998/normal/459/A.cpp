#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    if(x1==x2){
        cout<<x1+abs(y1-y2)<<' '<<y1<<' '<<x2+abs(y1-y2)<<' '<<y2<<'\n';
        return 0;
    }
    else if(y1==y2){
        cout<<x1<<' '<<y1+abs(x1-x2)<<' '<<x2<<' '<<y2+abs(x1-x2)<<'\n';
        return 0;
    }

    if(abs(x1-x2)==abs(y1-y2)){
        cout<<x1<<' '<<y2<<' '<<x2<<' '<<y1<<'\n';
    }
    else{
        cout<<"-1\n";
    }

    return 0;
}