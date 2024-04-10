#include<bits/stdc++.h>
using namespace std;
#define left fuckyougcc
#define right fuckyougcctoo
char a[1010101];
int left[1010101];
int right[1010101];
int value[1010101];
bool change[1010101];
void dfs(int x)
{
    //printf("C%d\n", x);
    switch(a[x])
    {
        case 'I':
            change[x] = true;
            return;
        case 'N':
            dfs(left[x]);
            return;
        case 'A':
            if(value[x] == 1)
            {
                dfs(left[x]);
                dfs(right[x]);
            }
            else
            {
                if(value[right[x]] && !value[left[x]]) dfs(left[x]);
                if(value[left[x]] && !value[right[x]]) dfs(right[x]);
            }
            return;
        case 'O':
            if(value[x] == 0)
            {
                dfs(left[x]);
                dfs(right[x]);
            }
            else
            {
                //printf("%d %d\n", left[x], right[x]);
                if(!value[right[x]] && value[left[x]]) dfs(left[x]);
                if(!value[left[x]] && value[right[x]]) dfs(right[x]);
            }
            return;
        case 'X':
            dfs(left[x]);
            dfs(right[x]);
            return;
    }
}
int calc(int x)
{
    int q, s;
    switch(a[x])
    {
        case 'I':
            value[x] = left[x];
            return value[x];
        case 'N':
            value[x] = !calc(left[x]);
            return value[x];
        case 'A':
            q = calc(left[x]);
            s = calc(right[x]);
            value[x] = (q && s);
            return value[x];
        case 'X':
            value[x] = (calc(left[x]) != calc(right[x]));
            return value[x];
        case 'O':
            q = calc(left[x]);
            s = calc(right[x]);
            value[x] = (q || s);
            return value[x];
    }
}

int N;
int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; ++i)
    {
        char buf[99];
        scanf("%s", buf);
        a[i] = *buf;
        switch(*buf)
        {
            case 'A':
            case 'X':
            case 'O':
                scanf("%d%d", left+i, right+i);
                break;
            case 'I':
            case 'N':
                scanf("%d", left+i);
                break;
        }
    }
    int ans = calc(1);
    dfs(1);
    //for(int i=1; i<=N; ++i)  printf("%3d: %d\n", i, value[i]);
    for(int i=1; i<=N; ++i)
        if(a[i] == 'I')
        {
            if(change[i]) printf("%d", 1-ans);
            else printf("%d", ans);
        }
    puts("");
    return 0;
}