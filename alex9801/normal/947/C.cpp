#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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

int arr[300010];
int key[300010];
int mem[9000010][2];
int cnt[9000010];
int nxt = 1;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(i = 0; i < n; i++)
        scanf("%d", &key[i]);

    for(i = 0; i < n; i++)
    {
        int c = 0;
        for(j = 29; j >= 0; j--)
        {
            cnt[c]++;
            if(key[i] & (1 << j))
            {
                if(!mem[c][1])
                    mem[c][1] = nxt++;
                c = mem[c][1];
            }
            else
            {
                if(!mem[c][0])
                    mem[c][0] = nxt++;
                c = mem[c][0];
            }
        }
        cnt[c]++;
    }

    for(i = 0; i < n; i++)
    {
        int c = 0;
        int r = arr[i];
        for(j = 29; j >= 0; j--)
        {
            cnt[c]--;
            if(arr[i] & (1 << j))
            {
                if(!mem[c][1] || !cnt[mem[c][1]])
                    c = mem[c][0];
                else
                {
                    r ^= 1 << j;
                    c = mem[c][1];
                }
            }
            else
            {
                if(!mem[c][0] || !cnt[mem[c][0]])
                {
                    r ^= 1 << j;
                    c = mem[c][1];
                }
                else
                    c = mem[c][0];
            }
        }
        cnt[c]--;
        printf("%d ", r);
    }

    return 0;
}