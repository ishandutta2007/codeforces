#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

bool check (char a, char b)
{
    int a1, b1;
    if (a >= 6 + '0' && a <= 9 + '0')
        a1 = a;
    else
    {
        if ('T' == a)
            a1 = '0' + 10;
        if ('J' == a)
            a1 = '0' + 11;
        if ('Q' == a)
            a1 = '0' + 12;
        if ('K' == a)
            a1 = '0' + 13;
        if ('A' == a)
            a1 = '0' + 14;
    }
    if (b >= 6 + '0' && b <= 9 + '0')
        b1 = b;
    else
    {
        if ('T' == b)
            b1 = '0' + 10;
        if ('J' == b)
            b1 = '0' + 11;
        if ('Q' == b)
            b1 = '0' + 12;
        if ('K' == b)
            b1 = '0' + 13;
        if ('A' == b)
            b1 = '0' + 14;
    }
    if (a1 > b1)
        return true;
    else
        return false;
}

//6, 7, 8, 9, T, J, Q, K  A

int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char ch, s1[10], s2[10];
    cin >> ch;
    cin >> s1 >> s2;
   // scanf("%c", &ch);
   // scanf("%s%s", s1, s2);

    if (check(s1[0], s2[0]))
    {
        if (s1[1] == ch || s1[1] == s2[1])
            printf("%s", "YES");
        else
            printf("%s", "NO");
    }
    else
    {
        if (s1[1] == ch && s2[1] != ch)
            printf("%s", "YES");
        else
            printf("%s", "NO");
    }

  //  printf("%c\n", ch);
 //   printf("%s %s", s1, s2);

    return 0;
}