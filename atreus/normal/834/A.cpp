#include <iostream>
#include <string>

using namespace std;

int main ()
{
    char a, b, x;
    cin >> a >> b;
    int n, z;
    cin >> n;
    z = n % 4;
    if (a == 'v')
    {
        if (z == 0)
            cout << "undefined" << endl;
        else if (z == 1){
            x = b;
            if (x == '<')
                cout << "cw" << endl;
            else
                cout << "ccw" << endl;
        }
        else if (z == 2)
            cout << "undefined" << endl;
        else {
            x = b;
            if (x == '>')
                cout << "cw" << endl;
            else
                cout << "ccw" << endl;
        }
    }
     if (a == '<')
    {
        if (z == 0)
            cout << "undefined" << endl;
        else if (z == 1){
            x = b;
            if (x == '^')
                cout << "cw" << endl;
            else
                cout << "ccw" << endl;
        }
        else if (z == 2)
            cout << "undefined" << endl;
        else {
            x = b;
            if (x == 'v')
                cout << "cw" << endl;
            else
                cout << "ccw" << endl;
        }
    }
     if (a == '^')
    {
        if (z == 0)
            cout << "undefined" << endl;
        else if (z == 1){
            x = b;
            if (x == '>')
                cout << "cw" << endl;
            else
                cout << "ccw" << endl;
        }
        else if (z == 2)
            cout << "undefined" << endl;
        else {
            x = b;
            if (x == '<')
                cout << "cw" << endl;
            else
                cout << "ccw" << endl;
        }
    }
     if (a == '>')
    {
        if (z == 0)
            cout << "undefined" << endl;
        else if (z == 1){
            x = b;
            if (x == 'v')
                cout << "cw" << endl;
            else
                cout << "ccw" << endl;
        }
        else if (z == 2)
            cout << "undefined" << endl;
        else {
            x = b;
            if (x == '^')
                cout << "cw" << endl;
            else
                cout << "ccw" << endl;
        }
    }

}