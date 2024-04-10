#include <bits/stdc++.h>

using namespace std;

int cnt, sum;

void solve(vector<int> x, int k)
{
    int n = x.size();
    if(k == 0)
    {
        cnt++;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                sum += x[j] < x[i];
        return;
    }
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
        {
            vector<int> t(x);
            for(int k = i; k <= j; k++)
                t[k] = x[i + j - k];
            solve(t, k - 1);
        }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for(int i = 0; i < n; i++)
        cin >> x[i];
    solve(x, k);
    cout << fixed << setprecision(15) << 1. * sum / cnt << "\n";
    return 0;
}