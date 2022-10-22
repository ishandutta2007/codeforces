#include <bits/stdc++.h>

using namespace std;

typedef long long li;

bool can_fit(vector<int> a, int s)
{
    sort(a.begin(), a.end());
    
    const int maxN = 1000500;
    bitset<maxN> can;
    can[0] = 1;
    
    int n = a.size();
    for (int l = 0; l < n;)
    {
        int r = l;
        while (r + 1 < n && a[r + 1] == a[r]) r++;
        
        int cnt = r - l + 1;
        
        int shiftp = a[l];
        //printf("cnt %d num %d\n", cnt, shiftp);
        
        bitset<maxN> p = can << shiftp;
#if 0
        printf("pstart: ");
        for (int i = 0; i <= s; i++)
            printf("%d", p[i] ? 1 : 0);
        printf("\n");
#endif
        int accshift = 0;
        while (cnt)
        {
            if (cnt % 2 == 1)
            {
                can = can | (p << accshift);
                accshift += shiftp;
            }
            
            cnt /= 2;
            
            //printf("cnt %d shiftp %d\n", cnt, shiftp);
            
            if (cnt)
                p = p | (p << shiftp);
            shiftp *= 2;
            
#if 0
            printf("p: ");
            for (int i = 0; i <= s; i++)
                printf("%d", p[i] ? 1 : 0);
            printf("\n");
#endif
        }
        
        if (can[s])
            return true;
        
#if 0
        for (int i = 0; i <= s; i++)
            printf("%d", can[i] ? 1 : 0);
        printf("\n");
#endif
        
        l = r + 1;
    }
    
    return can[s];
}

void solve(bool read)
{
    int n, k;
    if (read)
        cin >> n >> k;
    else
        n = 5, k = rand() % n + 1;
    
    int korig = k;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        if (read)
        {
            cin >> p[i];
            p[i]--;
        }
        else
        {
            p[i] = i;
        }
    }
    
    if (!read)
    {
        random_shuffle(p.begin(), p.end());
    }
    
    vector<int> l;
    
    vector<char> used(n, false);
    for (int i = 0; i < n; i++)
    {
        if (used[i]) continue;
        
        int length = 0;
        
        int now = i;
        while (!used[now])
        {
            used[now] = true;
            now = p[now];
            length++;
        }
        
        l.push_back(length);
        //printf("length %d\n", length);
    }
    
    int max_can = 0, min_can = 0;
    sort(l.begin(), l.end());
    
    /*
    
    int kr = k;
    for (int i = 0; i < (int)l.size(); i++)
    {
        if (kr >= l[i])
        {
            kr -= l[i];
            min_can += l[i];
            
            if (kr == 0) break;
        }
        else
        {
            min_can += kr + 1;
            break;
        }
    }*/
    
    min_can = can_fit(l, k) ? k : k + 1;
    
    sort(l.rbegin(), l.rend());
    int kr = k;
    for (int i = 0; i < (int)l.size(); i++)
    {
        int can = l[i] / 2;
        
        l[i] -= min(kr, can) * 2;
        max_can += min(kr, can) * 2;
        kr -= min(kr, can);
    }
    
    if (kr != 0)
        for (int i = 0; i < (int)l.size(); i++)
        {
            if (kr == 0)
                break;
            
            assert(l[i] == 0 || l[i] == 1);
            
            if (l[i] == 1)
            {
                kr--;
                max_can++;
            }
        }
    
    cout << min_can << " " << max_can << endl;
    
    if (!read)
    {
        int m1 = 1e9, m2 = 0;
        
        printf("%d %d\n", n, korig);
        for (int i = 0; i < n; i++)
            printf("%d ", p[i] + 1);
        printf("\n");
        
        for (int mask = 0; mask < (1 << n); mask++)
            if (__builtin_popcount(mask) == korig)
            {
                int x = 0;
                for (int i = 0; i < n; i++)
                    if ((mask & (1 << i)) || (mask & (1 << p[i])))
                    {
                        x++;
                    }
                
                /*printf("mask ");
                for (int i = 0; i < n; i++)
                    printf(mask & (1 << i) ? "1" : "0");
                printf(" can %d\n", x);*/
                    
                m1 = min(m1, x);
                m2 = max(m2, x);
            }
            
        printf("expected %d %d\n", m1, m2);
        assert(m1 == min_can && m2 == max_can);
    }
}

int main()
{
#if 0
    int s = 0;
    vector<int> v;
    for (int i = 1; i <= 1000; i++)
    {
        v.push_back(i);
        s += i;
    }
    
    printf("%d\n", can_fit(v, s));
    return 0;
#endif
    
    //printf("%d\n", can_fit(vector<int> { 1, 1, 3 }, 5));
    //return 0;
    
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve(true);
    
    //while (true)
    //    solve(false);
    
    return 0;
}