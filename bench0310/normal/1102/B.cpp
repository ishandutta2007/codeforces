#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int a;
    vector<int> v[5001];
    for(int i=0;i<n;i++)
    {
        cin >> a;
        v[a].push_back(i);
    }
    bool good=0;
    int b=1;
    int c[n];
    for(int o=1;o<=5000;o++)
    {
        if((int)v[o].size()>k)
        {
            good=0;
            break;
        }
        for(int i=0;i<(int)v[o].size();i++)
        {
            c[v[o][i]]=b;
            b++;
            if(b>k) b=good=1;
        }
    }
    if(good)
    {
        cout << "YES" << endl;
        for(int i=0;i<n;i++) cout << c[i] << " ";
        cout << endl;
    } else cout << "NO" << endl;
    return 0;
}