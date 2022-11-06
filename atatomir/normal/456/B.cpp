#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[100005];
long n,x;

int main()
{
    scanf("%s",s);
    n = strlen(s);

    if(n == 0){
        cout << 4;
        return 0;
    } else
    if(n == 1){
        x =  s[n-1] - '0';
    } else {
        x = 10*(s[n-2] - '0') + s[n-1] - '0';
    }
    x %= 4;

    switch (x){
    case 0: cout << (1 + 6 + 1 + 6)% 5;
            break;
    case 1: cout << (1 + 2 + 3 + 4)% 5;
            break;
    case 2: cout << (1 + 4 + 9 + 6)% 5;
            break;
    case 3: cout << (1 + 8 + 7 + 4)% 5;
            break;
    }

    return 0;
}