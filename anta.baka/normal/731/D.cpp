#include <bits/stdc++.h>

using namespace std;

int n, c;
vector<int> a[500000];
int t[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> c;
    for(int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        a[i].resize(len);
        for(int j = 0; j < len; j++) cin >> a[i][j], a[i][j]--;
    }
    for(int i = 1; i < n; i++)
    {
        int n0 = a[i - 1].size();
        int n1 = a[i].size();
        int pos = -1;
        for(int j = 0; j < min(n0, n1); j++)
            if(a[i - 1][j] != a[i][j])
            {
                pos = j;
                break;
            }
        if(pos == -1)
        {
            if(n0 <= n1) { t[0]++; t[c]--; continue; } // [0, c - 1]
            else return cout << -1, 0;
        }
        if(a[i - 1][pos] < a[i][pos])
        {
            t[0]++; t[c - a[i][pos]]--; // [0, c - a[i][pos] - 1]
            t[c - a[i - 1][pos]]++; t[c]--; // [c - a[i - 1][pos], c - 1]
        }
        else
        {
            t[c - a[i - 1][pos]]++; t[c - a[i][pos]]--; // [c - a[i - 1][pos], c - a[i][pos] - 1]
        }
    }
    int cnt = 0;
    for(int i = 0; i < c; i++)
    {
        cnt += t[i];
        if(cnt == n - 1) return cout << i, 0;
    }
    cout << -1;
}