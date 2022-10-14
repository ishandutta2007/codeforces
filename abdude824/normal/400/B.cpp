#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int n, m;
char s[1010][1010];
int main()
{
    scanf("%d %d\n", &n, &m);
    set<int> z;
    for (int i=0;i<n;++i)
    {
        gets(s[i]);
        int G=-1, S=-1;
        for (int j=0;j<m;++j) if (s[i][j]=='G') G=j; else if (s[i][j]=='S') S=j;
        if (S<G) { puts("-1"); return 0; }
        z.insert(S-G);
    }
    printf("%d\n", int(z.size()));
    return 0;
}