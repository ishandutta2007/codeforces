#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long double ftype;

const int maxPrice = 10005;

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<int> l(n), r(n);
    
    for (int i = 0; i < n; i++)
        scanf("%d %d", &l[i], &r[i]);
    
    ftype total = 1;
    
    for (int i = 0; i < n; i++)
        total *= (r[i] - l[i] + 1);
    
    vector<vector<int>> var;
    int nTotal = 1;
    for (int i = 0; i < n - 1; i++) nTotal *= 3;
    
    for (int i = 0; i < nTotal; i++)
    {
        vector<int> now(n - 1);
        int x = i;
        for (int i = 0; i < n - 1; i++)
        {
            now[n - i - 2] = x % 3;
            x /= 3;
        }
        
        int nEq = 0, nMore = 0;
        for (int i = 0; i < n - 1; i++)
            if (now[i] == 1)
                nEq++;
            else if (now[i] == 2)
                nMore++;
            
        if (nEq == 0 && nMore == 0) continue;
        
        var.push_back(now);
    }
    
    /*for (auto it: var)
    {
        for (auto x: it) printf("%d ", x);
        printf("\n");
    }*/
    
    ftype answer = 0;
    ftype totalTwo = 0;
    
    for (int winner = 0; winner < n; winner++)
    {
        vector<int> other;
        for (int i = 0; i < n; i++)
            if (i != winner)
                other.push_back(i);
            
        /*printf("winner %d other ", winner);
        for (auto it: other) printf("%d ", it);
        printf("\n");*/
        
        // winner is paid price
        
        for (int p = l[winner]; p <= r[winner]; p++)
            for (vector<int>& variant: var)
            {
                ftype nWays = 1;
                
                int nEq = 0, nMore = 0;
                int moreMin = p + 1, moreMax = maxPrice;
                
                for (int i = 0; i < n - 1; i++)
                    if (variant[i] == 0)
                    {
                        int from = l[other[i]];
                        int to = min(p - 1, r[other[i]]);
                        
                        if (to < from)
                            nWays = 0;
                        else
                            nWays *= (to - from + 1);
                    }
                    else if (variant[i] == 1)
                    {
                        nEq++;
                        
                        if (!(p >= l[other[i]] && p <= r[other[i]]))
                            nWays = 0;
                    }
                    else if (variant[i] == 2)
                    {
                        nMore++;
                        moreMin = max(moreMin, l[other[i]]);
                        moreMax = min(moreMax, r[other[i]]);
                    }
                    
                if (nMore > 1) continue;
                    
                if (nMore != 0)
                {
                    if (moreMax < moreMin)
                        nWays = 0;
                    else
                        nWays *= (moreMax - moreMin + 1);
                    
                    answer += nWays * p / (nEq + 1);
                    totalTwo += nWays / (nEq + 1);
                }
                else if (nEq != 0)
                {
                    answer += nWays * p / (nEq + 1);
                    totalTwo += nWays / (nEq + 1);
                }
                
                if (nWays < 1e-8) continue;
                
                /*printf("%d is %d selected ", winner, p);
                for (int i = 0; i < n - 1; i++)
                    printf("%d[%c] ", other[i], variant[i] == 0 ? '<' : (variant[i] == 1 ? '=' : '>'));
                printf("%lf\n", nWays);*/
            }
    }
    
    
    //cout << totalTwo << endl;
    
    //cout << answer << " " << total << endl;
    
    answer /= totalTwo;
    cout.precision(12);
    cout << fixed << answer << endl;
    
    /*vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;
    
    ftype win = 0;
    
    ftype totalTwo = 0;
    
    do
    { 
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < maxPrice; j++)
                d[i][j] = 0;
        
        for (int i = l[order[0]]; i <= r[order[0]]; i++)
            d[0][i] = 1;
        
        for (int i = 0; i < n - 1; i++)
            for (int from = 0; from < maxPrice; from++)
                for (int j = max(from + 1, l[order[i + 1]]); j <= r[order[i + 1]]; j++)
                {
                    if (d[i][from] > 0)
                        cout << fixed << setprecision(1) << "d[" << i << "][" << j << "] = " << d[i][from] << endl;
                    
                    totalTwo += d[i][from];
                    
                    if (i + 1 < n - 1)
                        d[i + 1][j] += d[i][from];
                    else
                        win += d[i][from] * from;
                }
                
        for (int nLastSame = 1; nLastSame <= n; nLastSame++)
            for (int last = 0; last < maxPrice; last++)
            {
                bool fail = false;
                
                for (int i = n - nLastSame; i < n; i++)
                    if (!(last >= l[i] && last <= r[i]))
                    {
                        fail = true;
                        break;
                    }
                    
                if (fail) continue;
                
                totalTwo += d[n - nLastSame][last] / nLastSame;
                win += d[n - nLastSame][last] / nLastSame;
            }
    }
    while (next_permutation(order.begin(), order.end()));
    
    cout.precision(12);
    
    cout << totalTwo << endl;
    
    ftype answer = win / total;
    cout << fixed << setprecision(12) << answer << endl;
    cout << win << " " << total << endl;*/
    
    return 0;
}