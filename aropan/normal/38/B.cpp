#include <cstdio>
#define sqr(x) ((x)*(x))

using namespace std;


char x1, y1, x2, y2;
int ans;

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%c%c\n%c%c", &x1, &y1, &x2, &y2);
    x1 -= 'a';
    y1 -= '1';
    x2 -= 'a';
    y2 -= '1';
    
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if (i == x1 || j == y1 || i == x2 && j == y2) continue;
            if (sqr(i - (int)x2) + sqr(j - (int)y2) == 5) continue;
            if (sqr(i - (int)x1) + sqr(j - (int)y1) == 5) continue;
            ans++;
        }
    printf("%d\n", ans);
    return 0;
}