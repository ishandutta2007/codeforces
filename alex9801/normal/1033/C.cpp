#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
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
#include <iterator>
#include <cmath>

using namespace std;

int arr[100010];
char mem[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    vector<pair<int, int>> v;
    for(i = 0; i < n; i++)
        v.push_back({ arr[i], i });

    sort(v.rbegin(), v.rend());
    for(auto p : v)
    {
        int x = p.second;
        
        mem[x] = 'B';

        int y = x - arr[x];
        while(y >= 0)
        {
            if(arr[y] > arr[x] && mem[y] == 'B')
            {
                mem[x] = 'A';
                break;
            }
            y -= arr[x];
        }

        y = x + arr[x];
        while(y < n)
        {
            if(arr[y] > arr[x] && mem[y] == 'B')
            {
                mem[x] = 'A';
                break;
            }
            y += arr[x];
        }
    }

    printf("%s\n", mem);
    return 0;
}