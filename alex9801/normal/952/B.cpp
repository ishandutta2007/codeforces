#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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

char tmp[1000];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int nocnt = 0;

    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
        fflush(stdout);

        fgets(tmp, 100, stdin);

        if(strcmp(tmp, "terrible\n") == 0 || strcmp(tmp, "don't even\n") == 0 || strcmp(tmp, "worse\n") == 0 || strcmp(tmp, "are you serious?\n") == 0 || strcmp(tmp, "go die in a hole\n") == 0 || strcmp(tmp, "no way\n") == 0)
        {
            printf("grumpy\n");
            fflush(stdout);
            return 0;
        }

        if(strcmp(tmp, "great!\n") == 0 || strcmp(tmp, "cool\n") == 0 || strcmp(tmp, "not bad\n") == 0 || strcmp(tmp, "don't think so\n") == 0 || strcmp(tmp, "don't touch me!\n") == 0)
        {
            printf("normal\n");
            fflush(stdout);
            return 0;
        }

        if(strcmp(tmp, "no\n") == 0)
        {
            nocnt++;
            if(nocnt == 4)
            {
                printf("normal\n");
                fflush(stdout);
                return 0;
            }
        }
    }
    return 0;
}