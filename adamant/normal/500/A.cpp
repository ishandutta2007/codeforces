#include <bits/stdc++.h>

using namespace std;

 main()
 {
     ios::sync_with_stdio(0);
     cin.tie(0);
     int n, t;
     cin >> n >> t;
     int a[n - 1];
     for(auto &it: a) cin >> it;
     int b[n];
     memset(b, 0, sizeof(b));
     for(int i = 0; ; i += a[i])
     {
         b[i] = 1;
         if(i == n - 1) break;
     }
     cout <<(b[t - 1] ? "YES" : "NO");
 }