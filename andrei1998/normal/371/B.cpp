#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a,B=0,k=0,l=0,p=0,n=0,b=0,t=0,x=0,y=0;
    cin>>a>>B;

    while(a%2==0)
    {
        k++;
        a/=2;
    }

    while(a%3==0)
    {
        l++;
        a/=3;
    }

    while(a%5==0)
    {
        p++;
        a/=5;
    }

    while(B%2==0)
    {
        n++;
        B/=2;
    }

    while(B%3==0)
    {
        b++;
        B/=3;
    }

    while(B%5==0)
    {
        t++;
        B/=5;
    }

    x=a;
    y=B;

    if(x!=y)
    {
        cout<<"-1\n";
        return 0;
    }
    else
        cout<<(abs(k-n)+abs(b-l)+abs(p-t))<<'\n';


    return 0;
}