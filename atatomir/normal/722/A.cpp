#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

int tp, n1, n2;
char s[11];

int ans;

void print_sol() {
    if (n1 < 10) printf("0");
    printf("%d:", n1);

    if (n2 < 10) printf("0");
    printf("%d", n2);

    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s\n", s + 1);
    if (s[1] == '1')
        tp = 12;
    else
        tp = 24;

    scanf("%s", s + 1);
    n1 = (s[1] - '0') * 10 + s[2] - '0';
    n2 = (s[4] - '0') * 10 + s[5] - '0';

    if (n2 >= 60) {
        ans++;
        n2 %= 10;
    }

    if (tp == 12) {
        if (n1 == 0) {
            ans++;
            n1 = 10;
            print_sol();
        }

        if (n1 > 12) {
            ans++;
            n1 %= 10;
            if (n1 == 0) n1 = 10;
            print_sol();
        }
    } else {
        if (n1 >= 24) {
            ans++;
            n1 %= 10;
            print_sol();
        }
    }

    print_sol();

    return 0;
}