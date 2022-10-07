#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
const long long p = 1e9 + 7;
struct brack{
    long long a[3][3];
};

brack free1;
string s;


brack rec(int l, int r){
    int d = 1, i = l, j, j1, ll ,rr;
    brack k1, k2, k3;
    k1 = free1;
    k2 = free1;
    k3 = free1;
 //   memset(k1, 0, sizeof k1);
  //  memset(k2, 0, sizeof k2);
   // memset(k3, 0, sizeof k3);
    if (l + 1 == r){
        k1.a[0][2] = 1;
        k1.a[1][2] = 1;
        k1.a[2][0] = 1;
        k1.a[2][1] = 1;
        return k1;
    }
    while (d != 0){
        i++;
        if (s[i] == '(')
            d++;
        else
            d--;
    }
    if (i == r){
        k1 =  rec(l + 1, r - 1);
        for (j = 0; j < 3; j++)
            for (j1 = 0; j1 < 3; j1++)
                if (j != 0)
                    k2.a[0][2] = (k2.a[0][2] + k1.a[j][j1]) % p;
        for (j = 0; j < 3; j++)
            for (j1 = 0; j1 < 3; j1++)
                if (j != 1)
                    k2.a[1][2] = (k2.a[1][2] + k1.a[j][j1]) % p ;
        for (j = 0; j < 3; j++)
            for (j1 = 0; j1 < 3; j1++)
                if (j1 != 0)
                    k2.a[2][0] = (k2.a[2][0] + k1.a[j][j1]) % p;
        for (j = 0; j < 3; j++)
            for (j1 = 0; j1 < 3; j1++)
                if (j1 != 1)
                    k2.a[2][1] = (k2.a[2][1] + k1.a[j][j1]) % p;
        return k2;
    }
    k1 = rec(l, i);
    k2 = rec(i + 1, r);
    for (ll = 0; ll < 3; ll++)
        for (rr = 0; rr < 3; rr++)
            for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                    if (i != j || i == 2)
                        k3.a[ll][rr] = (k3.a[ll][rr] + k1.a[ll][i] * k2.a[j][rr]) % p;
    return k3;
}

int main()
{
    int n, i, j, sum = 0;
    cin >> s;
    n = s.length();
    brack k;
    k = rec(0, n - 1);
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            sum = (sum + k.a[i][j]) % p;

    cout << sum;

    return 0;
}