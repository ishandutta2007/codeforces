#include <bits/stdc++.h>

using namespace std;

typedef long long li;

int n;
vector<li> rs, s, ps;

void addSegment(int x, int i, int l, int r)
{
    if (l >= r) return;
    
    int fl = abs((x + l) % n - i);
    int flp = abs((x + l + 1) % n - i);
    int delta = flp - fl;
    
    s[l] += fl;
    s[r] -= fl;
    
    ps[l + 1] += delta;
    ps[r] -= delta;
    s[r] -= delta * (li)(r - l - 1);
}

void addPoint(int x, int y)
{
    s[x] += y;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    
    vector<int> pInv(n);
    for (int i = 0; i < n; i++)
        pInv[p[i]] = i;
    
    rs.resize(n + 1);
    s.resize(n + 1);
    ps.resize(n + 1);
    
    vector<li> real(n);
    
    for (int i = 0; i < n; i++)
    {
        int x = pInv[i];
        //if (i != 0) continue;
        
        /*for (int j = 0; j < n; j++)
        {
            real[j] += abs((x + j) % n - i);
        }*/
        
        int a = (-x) % n; a = (a + n) % n;
        int b = (i - x) % n; b = (b + n) % n;
        
        if (b < a) swap(a, b);
        
        //printf("x %d, pts %d %d\n", x, a, b);
        
        addSegment(x, i, 0, a);
        
        rs[a] += abs((x + a) % n - i);
        //printf("val %lld\n", abs((x + a) % n - i));
        addSegment(x, i, a + 1, b);
        
        if (a != b)
        {
            rs[b] += abs((x + b) % n - i);
        }
        addSegment(x, i, b + 1, n);
    }
    
    for (int i = 1; i < n; i++)
        ps[i] += ps[i - 1];
    
    for (int i = 0; i < n; i++)
        s[i] += ps[i];
    
    for (int i = 1; i < n; i++)
        s[i] += s[i - 1];
    
    for (int i = 0; i < n; i++)
        s[i] += rs[i];
    
    /*
    printf("value:\n");
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        printf("%d -> %lld (real %lld)\n", i, s[i], real[i]);
        if (s[i] != real[i])
            ok = false;
    }
    assert(ok);
    printf("\n");*/
    
    int shift = min_element(s.begin(), s.end() - 1) - s.begin();
    cout << s[shift] << " " << shift << endl;
    
    return 0;
}