#include <bits/stdc++.h>

using namespace std;

int bad = 0;
const int maxn = 2e5;
int a[maxn];
int n;

void change(int i, int c)
{
    if(i < n) bad -= (i % 2 == 0) && !(a[i] < a[i + 1]);
    if(i > 0) bad -= (i % 2 == 0) && !(a[i] < a[i - 1]);
    if(i < n) bad -= (i % 2 == 1) && !(a[i] > a[i + 1]);
    if(i > 0) bad -= (i % 2 == 1) && !(a[i] > a[i - 1]);
    a[i] = c;
    if(i < n) bad += (i % 2 == 0) && !(a[i] < a[i + 1]);
    if(i > 0) bad += (i % 2 == 0) && !(a[i] < a[i - 1]);
    if(i < n) bad += (i % 2 == 1) && !(a[i] > a[i + 1]);
    if(i > 0) bad += (i % 2 == 1) && !(a[i] > a[i - 1]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n - 1; i++)
        if((i % 2 == 1 && !(a[i] > a[i + 1])) || (i % 2 == 0 && !(a[i] < a[i + 1])))
            bad++;
    for(int i = 0; i < n - 1; i++)
        if((i % 2 == 1 && !(a[i] > a[i + 1])) || (i % 2 == 0 && !(a[i] < a[i + 1])))
        {
            for(int j = 0; j < n; j++)
            {
                if(j == i)
                    continue;
                int A = a[i];
                int B = a[j];
                change(i, B);
                change(j, A);
                ans += bad == 0;
                change(i, A);
                change(j, B);
            }
            for(int j = 0; j < n; j++)
            {
                if(j == i || j == i + 1)
                    continue;
                int A = a[i + 1];
                int B = a[j];
                change(i + 1, B);
                change(j, A);
                ans += bad == 0;
                change(i + 1, A);
                change(j, B);
            }
            break;
        }
    cout << ans << "\n";
}