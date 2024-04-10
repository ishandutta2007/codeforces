#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
    int x;
    cin >> x;
    return x;
}

struct fenwick
{
    int n;
    vector<int> a;
    
    fenwick(int n): n(n), a(n) {}
    
    void change(int index, int value)
    {
        for (int i = index; i < n; i = (i | (i + 1)))
            a[i] += value;
    }
    
    int query(int l)
    {
        if (l < 0) return 0;
        
        int sum = 0;
        for (int i = l; i >= 0; i = (i & (i + 1)) - 1)
            sum += a[i];
        return sum;
    }
    
    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

struct modsum
{
    int n, k;
    vector<fenwick> fenws;
    vector<int> oldvalue;
    
    modsum(int n = 0, int k = 0): n(n), k(k), oldvalue(n)
    {
        if (k != 0)
            fenws.assign(k, fenwick(n / k + 1));
    }
    
    void change(int index, int value)
    {
        fenws[index % k].change(index / k, value);
        //oldvalue[index] = value;
    }
    
    int query(int L, int R, int rest)
    {
        int answer = 0;
        
        //for (int rest = 0; rest < k; rest++)
        {
            int l = L / k;
            if (l * k + rest < L) l++;
            int r = R / k;
            if (r * k + rest > R) r--;
            
            if (l > r) return 0;
            
            answer += fenws[rest].query(l, r);
        }
        
        return answer;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.length();
    
    int nq;
    cin >> nq;
    
    modsum ms[11][4];
    for (int i = 1; i <= 10; i++)
        for (int j = 0; j < 4; j++)
            ms[i][j] = modsum(n, i);
    
    string symbol = "AGTC";
    
    for (int i = 0; i < n; i++)
    {
        for (int t = 0; t < 4; t++)
            if (s[i] == symbol[t])
            {
                for (int k = 1; k <= 10; k++)
                    ms[k][t].change(i, 1);
            }
    }
    
    for (int i = 0; i < nq; i++)
    {
        int op;
        cin >> op;
        
        if (op == 1)
        {
            int x;
            char c;
            cin >> x >> c;
            x--;
            
            if (s[x] == c) continue;
            
            for (int t = 0; t < 4; t++)
                if (s[x] == symbol[t] || c == symbol[t])
                {
                    for (int k = 1; k <= 10; k++)
                        ms[k][t].change(x, s[x] == symbol[t] ? -1 : 1);
                }
                
            s[x] = c;
        }
        else
        {
            int l, r;
            string e;
            cin >> l >> r >> e;
            l--; r--;
            
            int len = e.length();
            
            int answer = 0;
            
            for (int rest = 0; rest < len; rest++)
            {
                for (int j = 0; j < 4; j++)
                    if (symbol[j] == e[rest])
                    {
                        int got = ms[len][j].query(l, r, (l + rest) % len);
                        //printf("len %d symbol %d segment %d..%d rest %d got %d\n", len, j, l, r, rest, got);
                        answer += got;
                        break;
                    }
            }
            
            cout << answer << '\n';
        }
    }
    
    return 0;
}