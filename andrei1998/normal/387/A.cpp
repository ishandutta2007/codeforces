#include <iostream>

using namespace std;

int main()
{
    int sh,sm,th,tm;
    char aux;

    cin>>sh>>aux>>sm;
    cin>>th>>aux>>tm;

    sh-=th;
    sm-=tm;

    if(sm<0)
    {
        sm+=60;
        sh--;
    }
    sh=(sh+24)%24;

    if(sh<10)
        cout<<'0';
    cout<<sh<<':';
    if(sm<10)
        cout<<'0';
    cout<<sm<<'\n';

    return 0;
}