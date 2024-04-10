#include <bits/stdc++.h>

using namespace std;

 main()
 {
     //freopen("input.txt", "r", stdin);
     ios::sync_with_stdio(0);
     cin.tie(0);
     int n, m;
     cin >> n >> m;
     int b[n], c[m];
     int used[n];
     memset(used, 0, sizeof(used));
     vector<int> ans;
     for(auto &it: b) cin >> it;
     for(auto &it: c)
     {
         cin >> it;
         it--;
         if(used[it]) continue;
         used[it] = 1;
         ans.push_back(it);
     }
     int64_t sum = 0;
     for(auto it: c)
     {
         for(int i = 0; i < ans.size(); i++)
         {
             if(ans[i] == it)
             {
                 for(int j = i; j; j--)
                    ans[j] = ans[j - 1];
                 ans[0] = it;
                 break;
             }
             sum += b[ans[i]];
         }
     }
     cout << sum << endl;
 }