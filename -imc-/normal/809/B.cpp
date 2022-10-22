#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

const int MOD = 1e9 + 7;

typedef long long li;

int n, k;

string secret;
int nOps;
bool guessed;

int project(int x)
{
    int bestPos = -1;
    int best = 1e9;
    
    for (int i = 0; i < secret.size(); i++)
        if (secret[i] == '1' && abs(i - x) < best)
        {
            best = abs(i - x);
            bestPos = i;
        }
        
    assert(bestPos != -1);
    return bestPos;
}

bool query(int x, int y)
{
    nOps++;
    assert(x >= 0 && y >= 0 && x < n && y < n && x != y);
    if (secret.empty())
    {
        cout << "1 " << x + 1 << " " << y + 1 << "\n" << endl;
        string answer;
        cin >> answer;
        return answer == "TAK";
    }
    else
    {
        int a = project(x);
        int b = project(y);
        return abs(x - a) <= abs(y - b);
    }
}

void answer(int i, int j)
{
    guessed = true;
    if (secret.empty())
    {
        assert(i != j && i >= 0 && j >= 0 && i < n && j < n);
        cout << "2 " << i + 1 << " " << j + 1 << endl;
        exit(0);
    }
    else
    {
        //printf("%s\n", secret.c_str());
        //printf("answer %d %d\n", i + 1, j + 1);
        assert(i != j && i >= 0 && j >= 0 && i < n && j < n);
        assert(secret[i] == '1' && secret[j] == '1');
    }
}

bool leftSolve(int from)
{
    /*for (int i = max(from + 1, n - 1); i < n; i++)
        if (query(i, from))
        {
            answer(from, i);
            return true;
        }*/
        
    int low = from + 1;
    int high = n - 1;
    
    while (high - low > 3)
    {
        int m1 = low + (high - low) / 3;
        int m2 = high - (high - low) / 3;
        
        if (query(m1, m2))
            high = min((low + high) / 2, n - 1);
        else
            low = max(from + 1, (low + high) / 2);
    }
    
    for (int i = max(from + 1, low - 2); i <= min(high + 2, n - 1); i++)
        if (query(i, from))
        {
            answer(from, i);
            return true;
        }
        
#if 0
    printf("sorry failed to find left from %d on %s :(\n", from + 1, secret.c_str());
    for (int j = from + 1; j < n; j++) assert(secret[j] == '0');
    printf("but that's ok\n");
#endif
        
    return false;
}

bool rightSolve(int from)
{
    for (int i = 0; i < min(from, 2); i++)
        if (query(i, from))
        {
            answer(from, i);
            return true;
        }
        
    int low = 0;
    int high = from - 1;
    
    while (high - low > 3)
    {
        int m1 = low + (high - low) / 3;
        int m2 = low + (high - low) * 2 / 3;
        
        if (!query(m2, m1))
            high = min((low + high) / 2 + 1, from - 1);
        else
            low = max(0, (low + high) / 2 - 1);
    }
    
    //printf("conv to %d..%d\n", low, high);
    for (int i = max(0, low - 2); i <= min(high + 2, from - 1); i++)
        if (query(i, from))
        {
            answer(from, i);
            return true;
        }
        
#if 0
    printf("sorry failed to find right from %d on %s :(\n", from + 1, secret.c_str());
    for (int j = from - 1; j >= 0; j--) assert(secret[j] == '0');
    printf("but that's ok\n");
#endif
        
    return false;
}

void solve()
{
    if (query(0, 1))
    {
        bool ok = leftSolve(0);
        assert(ok);
    }
    else if (query(n - 1, n - 2))
    {
        // ...1
        bool ok = rightSolve(n - 1);
        assert(ok);
    }
    else
    {
        // both bounds are zeros
        // find left-right
        
        int low = 0, high = n - 2;
        //assert(!query(0, 1));
        //assert(query(n - 2, n - 1));
        
        while (low + 1 != high)
        {
            int m = (low + high) / 2;
            if (query(m, m + 1))
                high = m;
            else
                low = m;
        }
        
        int one = low + 1;
        if (leftSolve(one)) return;
        
        bool ok = rightSolve(one);
        assert(ok);
        
        /*assert(query(1, 0));
        assert(!query(n - 1, n - 2));
        low = 0;
        high = n - 2;
        
        while (low + 1 != high)
        {
            int m = (low + high) / 2;
            if (query(m, m + 1))
                low = m;
            else
                high = m;
        }
        
        int two = low;
        
        answer(one, two);*/
    }
}

int main()
{
    cin >> n >> k;
    solve();
#if 0
    
    while (true)
    {
        secret = "";
        n = 100000;
        
        assert(n >= 2);
        for (int i = 0; i < n; i++)
            if (rand() % 10000 == 0)
                secret += '1';
            else
                secret += '0';
        
        k = 0;
        while (true)
        {
            for (char c: secret)
                if (c == '1')
                    k++;
                
            if (k < 2)
            {
                secret[rand() % n] = '1';
                k = 0;
            }
            else
                break;
        }
        
        guessed = false;
        nOps = 0;
        solve();
        assert(guessed);
        printf("guessed in %d\n", nOps);
        assert(nOps <= 60);
    }
#endif
    
    return 0;
}