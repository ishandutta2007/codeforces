#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

char arr[5010];

int main()
{
    int n, r, i, j;
    scanf("%s", arr);

    n = strlen(arr);
    r = 0;

    for(i = 0; i < n; i++)
    {
        int c = 0;
        int q = 0;
        for(j = i; j < n; j++)
        {
            if(arr[j] == '(')
            {
                c++;
            }
            else if(arr[j] == ')')
            {
                c--;
                if(c < 0)
                    break;

                q = min(q, c / 2);

                if((j - i) % 2 == 1 && c - 2 * q == 0)
                    r++;
            }
            else
            {
                c++;
                q++;

                q = min(q, c / 2);

                if((j - i) % 2 == 1 && c - 2 * q == 0)
                    r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}