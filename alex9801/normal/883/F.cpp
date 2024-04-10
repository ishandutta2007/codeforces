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

char tmp[100];
set<string> s;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char t;
    int n, l, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s", tmp);
        l = strlen(tmp);
        string c;
        bool u = 0;
        for(j = l - 1; j >= 0; j--)
        {
            t = tmp[j];
            if(t == 'u')
            {
                u = 0;
                c.push_back('o');
                c.push_back('o');
            }
            else
            {
                if(t == 'k' && u)
                    continue;

                if(t == 'h')
                    u = 1;
                else
                    u = 0;

                c.push_back(t);
            }
        }
        s.insert(c);
    }
    printf("%d", s.size());
    return 0;
}