#include <bits/stdc++.h>

using namespace std;

vector<int> a;

bool ok(int i)
{
    if (i < 0 || i + 1 >= (int)a.size())
        return true;
    
    return (i % 2 == 0 && a[i + 1] > a[i]) || (i % 2 == 1 && a[i + 1] < a[i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    a.resize(n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    vector<int> pos;
    for (int i = 0; i + 1 < n; i++)
        if (!ok(i))
        {
            pos.push_back(i);
            pos.push_back(i + 1);
        }
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    
    if (pos.size() > 10)
    {
        printf("0\n");
        return 0;
    }
    
    set<pair<int, int>> answer;
    for (int i: pos)
        for (int j = 0; j < n; j++)
        {
            swap(a[i], a[j]);
            //printf("swap %d %d\n", i, j);
            bool fail = (!ok(i) || !ok(i - 1) || !ok(i + 1) || !ok(j) || !ok(j - 1) || !ok(j + 1));
            if (!fail)
                for (int x: pos)
                    if (!ok(x) || !ok(x - 1) || !ok(x + 1))
                    {
                        fail = true;
                        break;
                    }
            swap(a[i], a[j]);
            
            if (!fail)
            {
                int ii = i, jj = j;
                if (ii > jj)
                    swap(ii, jj);
                answer.insert(make_pair(ii, jj));
            }
        }
        
    printf("%d\n", (int)answer.size());
    
    return 0;
}