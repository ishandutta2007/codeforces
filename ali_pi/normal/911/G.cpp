#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

inline int in(){
int32_t x ; scanf("%d",&x);return x;}

const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9 + 10;
const int SQ = 3163;
int a[maxn];
int f[SQ][105],f2[105];

int32_t main()
{
    int n = in();
    for (int i = 0 ; i < n ; i++) a[i] = in();
    int q = in();
    for (int i = 0 ; i < SQ ; i ++)
        for (int j = 0 ; j <= 100 ; j ++) f[i][j] = j;

    while(q --)
    {
        int l = in() - 1 , r = in(), x = in() , y = in();
        while(l < r)
        {
            if (l + SQ <= r && l % SQ == 0)
            {
                int part = l/SQ;
                for (int pt = 0 ; pt <= 100 ; pt ++)
                    if (f[part][pt] == x) f[part][pt] = y;
                l += SQ;
            }
            else
            {
                int current = l/SQ;
                int part = current;
                current *= SQ;
                for (int pt = current ; pt < current + SQ && pt < n ; pt ++)
                {
                    if (f[part][a[pt]] + 1)
                        a[pt] = f[part][a[pt]];
                }
                for(int pt = 0 ; pt <= 100 ; pt ++) f[part][pt] = pt;
                while(l < current + SQ && l < r){
                    if (a[l] == x) a[l] = y;
                    l ++;
                }
            }
        }
    }
    for (int i = 0 ; i < n ; i ++)
        cout << f[i/SQ][a[i]] << " ";
}