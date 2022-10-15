#include <cstdio>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXH = 200007;
int H, M, n;
bool f[MAXH];
map <int, int> m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".ans", "w", stdout);
    #endif
    scanf("%d %d %d\n", &H, &M, &n);

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
    	char com;
    	int id, h;
    	scanf("%c", &com);
    	switch (com)
    	{
    		case '+':
    			scanf("%d %d\n", &id, &h);
    			while (f[h])
    			{
    				ans++;
    				h = (h + M) % H;
    			}
    			f[m[id] = h] = true;
    		break;

    		case '-':
    			scanf("%d\n", &id);
    			f[m[id]] = false;
    		break;
    	}
    }
    cout << ans << endl;
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}