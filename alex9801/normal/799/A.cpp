#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, t, k, d;
    scanf("%d%d%d%d", &n, &t, &k, &d);
    if((d+t)/t * k >= n)
        printf("NO");
    else
        printf("YES");
	return 0;
}