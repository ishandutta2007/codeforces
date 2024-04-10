#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a[4];
    long long s[4];
    for(int i = 1; i <= 3; i++)
        scanf("%lld", &a[i]);

    long long v = 1e9;
    printf("First\n%lld\n", v);
    fflush(stdout);

    int t;
    scanf("%d", &t);
    if(t <= 0)
        return 0;
    a[t] += v;

    for(int i = 1; i <= 3; i++)
        s[i] = a[i];
    sort(s + 1, s + 4);

    v = (s[2] - s[1]) + 2 * (s[3] - s[2]);
    printf("%lld\n", v);
    fflush(stdout);

    scanf("%d", &t);
    if(t <= 0)
        return 0;
    a[t] += v;

    for(int i = 1; i <= 3; i++)
        s[i] = a[i];
    sort(s + 1, s + 4);

    v = s[2] - s[1];
    assert(s[3] - s[2] == v);
    printf("%lld\n", v);
    fflush(stdout);

    scanf("%d", &t);
    if(t <= 0)
        return 0;

    assert(0);
    return 0;
}