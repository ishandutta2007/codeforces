#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <ctime>

using namespace std;

char f0[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char f1[] = "What are you doing while sending \"";
char f2[] = "\"? Are you busy? Will you send \"";
char f3[] = "\"?";

long long len[100010];
const long long MAXL = 1000000000000000001;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int q, n, l0, l1, l2, l3, i;
    long long k;
    scanf("%d", &q);

    l0 = strlen(f0);
    l1 = strlen(f1);
    l2 = strlen(f2);
    l3 = strlen(f3);

    len[0] = l0;
    for(i = 1; i <= 100000; i++)
        len[i] = min(MAXL, 2 * len[i - 1] + l1 + l2 + l3);

    for(i = 0; i < q; i++)
    {
        scanf("%d%lld", &n, &k);
        while(n > 0)
        {
            if(k <= l1)
            {
                printf("%c", f1[k - 1]);
                break;
            }
            else if(k <= l1 + len[n - 1])
            {
                k -= l1;
                n--;
            }
            else if(k <= l1 + len[n - 1] + l2)
            {
                printf("%c", f2[k - l1 - len[n - 1] - 1]);
                break;
            }
            else if(k <= l1 + len[n - 1] + l2 + len[n - 1])
            {
                k -= l1 + len[n - 1] + l2;
                n--;
            }
            else if(k <= l1 + len[n - 1] + l2 + len[n - 1] + l3)
            {
                printf("%c", f3[k - l1 - len[n - 1] - l2 - len[n - 1] - 1]);
                break;
            }
            else
            {
                printf(".");
                break;
            }
        }

        if(n == 0)
        {
            if(k <= l0)
                printf("%c", f0[k - 1]);
            else
                printf(".");
        }
    }
    return 0;
}