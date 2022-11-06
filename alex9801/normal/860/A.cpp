#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

char arr[5000];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int p;
    int n, c, i;
    scanf("%s", arr);

    n = strlen(arr);
    c = 0;
    for(i = 0; i<n; i++)
    {
        if(arr[i] == 'a' ||arr[i] == 'e' ||arr[i] == 'i' ||arr[i] == 'o' ||arr[i] == 'u')
        {
            c = 0;
        }
        else
        {
            c++;
            if(c == 1)
                p = arr[i];
            else
            {
                if(p != arr[i])
                    p = -1;
            }

            if(c >= 3 && p == -1)
            {
                printf(" ");
                c = 1;
                p = arr[i];
            }
        }
        printf("%c", arr[i]);
    }
    return 0;
}