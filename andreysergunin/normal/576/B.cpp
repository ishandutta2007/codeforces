#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 300000;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    int p[MAXN], v[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++)
        v[i] = 0;
    int k = 0;
    vector<int> a[MAXN];
    int c[MAXN];
    int v1 = 0, v2 = 0;
    bool f1 = false;
    bool f2 = false;
    bool f3 = true;
    
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            k++;
            c[k] = 0;
            for (int j = i; v[j] == 0; j = p[j])
            {
                c[k]++;
                v[j] = 1;
                a[k].push_back(j);
            }
            if (c[k] % 2 == 1)
                f3 = false;
            if (c[k] == 1)
            {
                f1 = true;
                v1 = i;
            }
            if (c[k] == 2)
            {
                f2 = true;
                v2 = i;
            }
        }
    }
    
    if (f1)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            if (i != v1)
                cout << v1 + 1 << " " << i + 1 << endl;
        return 0;
    }
    
    if (f2 && f3)
    {
        cout << "YES" << endl;
        cout << v2 + 1 << " " << p[v2] + 1 << endl;
        for (int i = 0; i < n; i++)
            v[i] = 0;
        v[v2] = 1;
        v[p[v2]] = 1;
        for (int i = 0; i < n; i++)
            if (v[i] == 0)
            {
                for (int j = i, t = 0; v[j] == 0; j = p[j], t++)
                {
                    v[j] = 1;
                    if (t % 2 == 0)
                        cout << v2 + 1 << " " << j + 1 << endl;
                    else
                        cout << p[v2] + 1 << " " << j + 1 << endl;
                }
            }
        return 0;
    }
    
    cout << "NO" << endl;
    return 0;
}