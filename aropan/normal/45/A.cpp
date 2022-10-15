#include <cstdio>
#include <cstring>

using namespace std;

const char s[12][100] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char a[100];
int x;

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%s", a);
    scanf("%d", &x);
    for (int i = 0; i < 12; i++)
        if (strcmp(s[i], a) == 0)
        {
            printf("%s\n", s[(i + x) % 12]);
            break;
        }
    return 0;
}