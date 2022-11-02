#include <bits/stdc++.h>

using namespace std;

pair<int, int> w[200000];
int pr[200001];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i].first;
        w[i].second = i + 1;
    }
    sort(w, w + n);
    string s;
    cin >> s;
    int j = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (s[i] == '0')
        {
            cout << w[j].second << " ";
            pr[j + 1] = j;
            j++;
        }
        else
        {
            int k = pr[j];
            cout << w[k].second << " ";
            pr[j] = pr[k];
        }
    }
}