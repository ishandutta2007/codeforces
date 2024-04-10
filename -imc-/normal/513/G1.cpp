#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

int n;

vector<int> p;
vector<int> l, r;

typedef long double ftype;
ftype nWays, answer;

void bf(int k)
{
    if (k == 0)
    {
        vector<int> pp = p;
        
        for (int i = 0; i < (int)l.size(); i++)
            reverse(pp.begin() + l[i], pp.begin() + r[i] + 1);
        
        //for (int i = 0; i < (int)l.size(); i++) printf("[%d %d] ", l[i], r[i]);
        //printf("\n");
        
        int inv = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (pp[j] < pp[i])
                    inv++;
        
        answer += inv;
        nWays++;
        return;
    }
    
    for (int ll = 0; ll < n; ll++)
        for (int rr = ll; rr < n; rr++)
        {
            l.push_back(ll);
            r.push_back(rr);
            bf(k - 1);
            l.pop_back();
            r.pop_back();
        }
}

int main()
{
    int k;
    scanf("%d %d", &n, &k);
    
    p.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    
    bf(k);
    
    answer /= nWays;
    
    cout << fixed << setprecision(12) << answer << endl;
    
    return 0;
}