#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char s[10], r[10];
    int mosbat1 = 0, manfi1 = 0, mosbat2 = 0, manfi2 = 0, alamatsoal = 0;
    long double d = 1;
    cin >> s >> r;
    for (int i = 0; i <= 9; i++){
        if (s[i] == '+')
            mosbat1 += 1;
        else if(s[i] == '-')
            manfi1 += 1;
        if (r[i] == '+')
            mosbat2 += 1;
        else if (r[i] == '-')
            manfi2 += 1;
        else if (r[i] == '?')
            alamatsoal += 1;
    }
    int b1, b2;
    b1 = mosbat1 - manfi1;
    b2 = mosbat2 - manfi2;
    int b3;
    if (b1 - b2 < 0)
        b3 = b2 - b1;
    else
        b3 = b1 - b2;
    int b4 = (alamatsoal - b3);
    int b5 = b4 / 2;
    if (b3 > alamatsoal || b4 % 2 == 1)
        cout << 0.000 << endl;
    else {
        int power1 = 1, power2 = 1, power3 = 1;
        for (int i = 1; i <= b5; i++)
            power1 *= i;
        for (int i = 1; i <= alamatsoal; i++)
            power2 *= i;
        for (int i = 1; i <= alamatsoal - b5; i++)
            power3 *= i;
        int c = power2 / (power1  * power3);
        for (int i = 1; i <= alamatsoal; i++)
            d *= 0.5;
        d = d * c;
        cout << fixed << setprecision(9) << d << endl;
    }
    return 0;
}