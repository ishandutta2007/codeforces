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

vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char d1[21];
char d2[21];
int n1, n2;


int get_day(char *s) {
    if (s[1] == 'm') return 1;
    if (s[3] == 'e') return 2;
    if (s[1] == 'w') return 3;
    if (s[2] == 'h') return 4;
    if (s[1] == 'f') return 5;
    if (s[2] == 'a') return 6;
    if (s[3] == 'n') return 7;
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s\n", d1 + 1);
    scanf("%s", d2 + 1);

    n1 = get_day(d1);
    n2 = get_day(d2);

    for (int i = 0; i + 1 < days.size(); i++) {
        int aux = n1 + days[i];
        aux %= 7;
        if (aux == 0) aux = 7;

        if (aux == n2) {
            printf("YES");
            return 0;
        }
    }

    printf("NO");


    return 0;
}