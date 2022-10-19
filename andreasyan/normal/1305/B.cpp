#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n;
char a[N];

vector<int> ans;

int main()
{
    scanf(" %s", a);
    n = strlen(a);
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (a[i] == '(' && a[j] == ')')
        {
            ans.push_back(i);
            ans.push_back(j);
            ++i;
            --j;
            continue;
        }
        if (a[i] == ')')
            ++i;
        if (a[j] == '(')
            --j;
    }
    sort(ans.begin(), ans.end());
    if (ans.empty())
    {
        printf("0\n");
        return 0;
    }
    printf("1\n");
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i] + 1);
    printf("\n");
    return 0;
}