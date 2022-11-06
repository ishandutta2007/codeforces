#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char arr[1000010];
const long long mod = 1000000007;

int main()
{
    int l, i;
    long long c, s;
    scanf("%s", arr);

    l = strlen(arr);

    c = s = 0;
    for(i = l-1; i>=0; i--)
    {
        if(arr[i] == 'a')
        {
            s = (s + c) % mod;
            c = (2 * c) % mod;
        }
        else
            c = (c + 1) % mod;
    }

    printf("%lld", s);
    return 0;
}