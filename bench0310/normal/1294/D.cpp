#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q,x;
    scanf("%d%d",&q,&x);
    set<int> s[q+1];
    for(int i=0;i<x;i++) s[0].insert(i);
    vector<int> cnt(x,0);
    vector<int> v(q,0);
    int now=0;
    while(q--)
    {
        int y;
        scanf("%d",&y);
        y%=x;
        s[cnt[y]].erase(y);
        cnt[y]++;
        s[cnt[y]].insert(y);
        v[cnt[y]]++;
        while(v[now+1]==x) now++;
        printf("%d\n",now*x+(*s[now].begin()));
    }
    return 0;
}