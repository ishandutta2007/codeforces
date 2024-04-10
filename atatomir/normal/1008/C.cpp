#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 100011;

int n, i, p;
pair<int, int> ord[maxN];
int ans[maxN];
vector<int> rez;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &ord[i].first);
        ord[i].second = i;
    }

    sort(ord + 1, ord + n + 1);

    p = 1;
    for (i = 1; i <= n; i++) {
        if (ord[p].first >= ord[i].first) 
            rez.pb(ord[i].first);
        else
            ans[ord[p++].second] = ord[i].first;
    }

    
    printf("%d", p - 1);
    return 0;
}