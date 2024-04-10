#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 111;

int n;
string a[MAXN];
string b[MAXN];
int ans[MAXN];
bool f[MAXN];

int x[26], y[26];

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
        
    for (int i = 0; i < n; i++)
        cin >> b[i];
        
    sort(a, a + n);
    sort(b, b + n);
    
    
    for (int i = 0; i < n; i++)
        x[a[i][0] - 'A']++;
    for (int i = 0; i < n; i++)
        y[b[i][0] - 'A']++;
    
    for (int i = 0; i < n; i++)
    {
        if (i) cout << ", ";
        cout << a[i] << " ";
        
        for (int j = 0; j < n; j++)
        {
            if (f[j]) continue;
            if (x[a[i][0] - 'A' ] > y[a[i][0] - 'A'] && x[b[j][0] - 'A' ] < y[b[j][0] - 'A'] || a[i][0] == b[j][0])
            {
                f[j] = true;
                x[a[i][0] - 'A']--;
                y[b[j][0] - 'A']--;
                cout << b[j];
                break;
            }
        }
    }
    cout << endl;
    return 0;
}