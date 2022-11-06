#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;

string arr[100010];
char tmp[100010];

bool chk[26];

bool exi[26];
int nex[26];
int prv[26];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, p, q, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s", tmp);
        arr[i] = tmp;
    }
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < arr[i].size(); j++)
        {
            p = arr[i][j] - 'a';
            exi[p] = 1;
            if(chk[p])
            {
                printf("NO");
                return 0;
            }
            chk[p] = 1;
        }
        for(j = 0; j < arr[i].size(); j++)
        {
            p = arr[i][j] - 'a';
            chk[p] = 0;
        }
    }

    memset(nex, -1, sizeof nex);
    memset(prv, -1, sizeof prv);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (int)arr[i].size() - 1; j++)
        {
            p = arr[i][j] - 'a';
            q = arr[i][j + 1] - 'a';
            if(nex[p] != -1 && nex[p] != q || prv[q] != -1 && prv[q] != p)
            {
                printf("NO");
                return 0;
            }
            nex[p] = q;
            prv[q] = p;
        }
    }

    string res;
    for(i = 0; i < 26; i++)
    {
        if(!exi[i] || prv[i] != -1)
            continue;

        p = i;
        while(p != -1)
        {
            if(chk[p])
            {
                printf("NO");
                return 0;
            }
            res.push_back(p + 'a');
            chk[p] = 1;
            p = nex[p];
        }
    }

    for(i = 0; i < n; i++)
    {
        if(res.find(arr[i]) == string::npos)
        {
            printf("NO");
            return 0;
        }
    }
    printf("%s", res.c_str());
    return 0;
}