#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m;
    string s;
    cin >> m >> s;
    
    string answer = "";
    
    int n = s.length();
    
    vector<char> filled(n, false);
    for (char c = 'a'; c <= 'z'; c++)
    {
        vector<char> old = filled;
        int nc = 0;
        vector<int> pos;
        vector<char> filledNow(n, false);
        for (int i = 0; i < n; i++)
            if (s[i] == c)
            {
                pos.push_back(i);
                nc++;
                int j = i;
                while (j >= 0 && j > i - m && !filledNow[j])
                {
                    filled[j] = filledNow[j] = true;
                    j--;
                }
            }
            
        bool fail = false;
        for (int i = 0; i < n - m + 1; i++)
            if (!filled[i])
            {
                //printf("shit %d\n", i);
                fail = true;
                break;
            }
            
        if (fail)
        {
            for (int i = 0; i < nc; i++)
                answer += c;
            continue;
        }
        
        filled = old;
        int minEmpty = 0;
        while (minEmpty < n - m + 1 && filled[minEmpty]) minEmpty++;
        
        int nAdd = 0;
        filledNow.assign(n, false);
        for (int i = 0; i < nc; i++)
        {
            if (minEmpty >= n - m + 1) break;
            
            if (i + 1 < nc && pos[i + 1] - m < minEmpty)
                continue;
            
            nAdd++;
            int j = pos[i];
            while (j >= 0 && j > pos[i] - m && !filledNow[j])
            {
                filled[j] = filledNow[j] = true;
                j--;
            }
            while (minEmpty < n && filled[minEmpty]) minEmpty++;
            
            if (minEmpty >= n - m + 1) break;
        }
        
        for (int i = 0; i < nAdd; i++)
            answer += c;
        break;
    }
    
    cout << answer << endl;
    
    return 0;
}