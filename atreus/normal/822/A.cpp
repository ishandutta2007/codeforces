#include <iostream>

using namespace std;

int main ()
{
    int A, B, n = 1;
    cin >> A >> B;
    if (A >= B)
    {
        for (int i = 1; i <= B; i++)
            n *= i;
        cout << n << endl;
    }
    else{
        for (int i = 1; i <= A; i++)
            n *= i;
        cout << n << endl;
    }
}