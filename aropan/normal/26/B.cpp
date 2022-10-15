#include <cstdio>

using namespace std;

char c;
int n, ans;

int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    while (scanf("%c", &c) == 1)
    {
        if (c == '(')
        {
            n++;
            ans++;
        }
        if (c == ')' && n)
        {
            n--;
            ans++;
        }
    }
    printf("%d\n", ans - n);
    
    return 0;
}