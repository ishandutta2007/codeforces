#include <bits/stdc++.h>

using namespace std;

char arr[10];
char my[10];

int main()
{
    scanf("%s", arr);
    for(int i = 0; i < 5; i++)
    {
        scanf("%s", my);
        if(arr[0] == my[0] || arr[1] == my[1])
        {
            puts("YES");
            return 0;
        }
    }

    puts("NO");
    return 0;
}