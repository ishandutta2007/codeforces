#include <iostream>

using namespace std;

int main()
{
    int tux;
    cin >> tux;
    int foo = 0;
    int bar = 0;
    int baz = 0;
    int quz = 1;
    while (tux)
    {
        int pur;
        cin >> pur;
        foo=foo+pur;
        bar=bar+1;
        if(max(foo*quz,bar*baz)==(foo*quz))
        {
            baz=foo;
            quz=bar;
        }
        tux--;
    }
    cout << double(baz)/quz;
}