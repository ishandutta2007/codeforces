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

using namespace std;

char arr[100];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int s, i;
    scanf("%s", arr);

    s = 0;
    for(i=0;arr[i];i++)
    {
        if('0' <= arr[i] && arr[i] <= '9')
        {
            if((arr[i]-'0') % 2)
                s++;
        }
        else
        {
            if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
                s++;
        }
    }
    printf("%d", s);
    return 0;
}