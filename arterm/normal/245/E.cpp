#include <iostream>

using namespace std;

int main()
{
    long a=0,x=0,y=0;
    char ch;
    while (cin>>ch){
        ch=='+' ? a++:a--;
        if (ch=='!')
        break;
        x=max(x,a);
        y=min(a,y);
    }
    cout<<x-y;
    return 0;
}