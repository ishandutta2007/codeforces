#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;

    int rasp=0;
    while(a>=b)
    {
        a-=b;
        a++;
        rasp+=b;
    }
    rasp+=a;

    cout<<rasp<<'\n';

    return 0;
}