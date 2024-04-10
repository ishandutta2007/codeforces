#include <iostream>

using namespace std;

int main()
{
    int w,h,w1,h1,w2,h2;
    cin>>w>>h>>w1>>h1>>w2>>h2;
    if (h1<h2)
    {
        swap(h1,h2);
        swap(w1,w2);
    }
    int i=h;
    while (i>=h1)
    {
        w=w+i;
        i--;
    }
    w=max(w-w1,0);
    while (i>=h2)
    {
        w=w+i;
        i--;
    }
    w=max(w-w2,0);
    while (i>0)
    {
        w=w+i;
        i--;
    }
    cout<<w;
    return 0;
}