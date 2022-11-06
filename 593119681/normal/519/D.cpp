#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, t, A[26];
LL ans, Sum[N];
map <LL, int> Map[26];
char s[N];

int main()
{
    for (int i = 0; i < 26; i ++)
        scanf("%d", A + i);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i < n; i ++)
    {
        Sum[i] = Sum[i - 1] + A[s[i] - 'a'];
        Map[s[i] - 'a'][Sum[i]] ++;
        ans += Map[s[i + 1] - 'a'][Sum[i]];
    }
    
    cout << ans << endl;
    
    return 0;
}