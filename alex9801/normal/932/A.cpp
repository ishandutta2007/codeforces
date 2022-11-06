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

char arr[10010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%s", arr);
    printf("%s", arr);

    int l = strlen(arr);

    reverse(arr, arr + l);

    printf("%s", arr);
    

    return 0;
}