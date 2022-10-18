#include <bits/stdc++.h>

using namespace std;

 main()
 {
     //freopen("input.txt", "r", stdin);
     ios::sync_with_stdio(0);
     cin.tie(0);
     int n;
     cin >> n;
     int p[n];
     for(auto &it: p) cin >> it;
     string x[n];
     for(auto &it: x) cin >> it;
     for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            x[i][j] -= '0';
     for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                x[i][j] |= x[i][k] & x[k][j];
     for(int i = 0; i < n; i++)
         for(int j = i + 1; j < n; j++)
            if(x[i][j] && p[j] < p[i])
                swap(p[i], p[j]);
     for(int i = 0; i < n; i++)
        cout << p[i] << ' ';
 }