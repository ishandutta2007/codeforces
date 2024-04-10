#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> m;

int
main(void)
{
int n;
register int counter = 0, i;
scanf("%d", &n);
for(i = 0; i < n; i++)
    {
    int x;
    scanf("%d", &x);
    if(m.upper_bound(x) != m.end())
        {
        counter += m.size();
        m.clear();
        }
    m.insert(pair<int, int>(x, x));
    }
printf("%d\n", counter);
return 0;
}