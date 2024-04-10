#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long li;

const int MAX = 1e6;

struct line
{
    double a, b;
    set<line>::iterator self;
    
    double eval(double x) const { return a * x + b; }
    
    bool operator<(const line& l) const;
    
    double inter(line l)
    {
        // ax + b = l.a x + l.b
        // x * (l.a - a) = b - l.b
        return (b - l.b) / (l.a - a);
    }
};

set<line> lines;

bool line::operator<(const line& l) const
{
    if (l.a < 0)
    {
        auto nxt = next(self);
        return nxt != lines.end() && nxt->eval(l.b) <= eval(l.b) + 1e-7;
    }
    return a > l.a;
}

bool eraseMid(line a, line b, line c)
{
    double x = a.inter(c);
    return b.eval(x) >= c.eval(x) - 1e-7;
}

set<line> all_lines;

// ax + b
void addLine(line l)
{
    all_lines.insert(l);
    
    set<line>::iterator it = lines.insert(l).first;
    line* lptr = (line*)&*it;
    lptr->self = it;
    //return;
    
    double eps = 1e-7;
    
    while (it != lines.begin() && abs(prev(it)->a - it->a) < eps)
    {
        if (prev(it)->b < it->b)
        {
            lines.erase(it);
            return;
        }
        else
        {
            lines.erase(prev(it));
            continue;
        }
    }
    
    while (next(it) != lines.end() && abs(next(it)->a - it->a) < eps)
    {
        if (next(it)->a < it->a)
        {
            lines.erase(it);
            return;
        }
        else
        {
            lines.erase(next(it));
            continue;
        }
    }
    
    if (it != lines.begin() && next(it) != lines.end() && eraseMid(*prev(it), *it, *next(it)))
    {
        lines.erase(it);
        return;
    }
    
    while (next(it) != lines.end() && next(next(it)) != lines.end() && eraseMid(*it, *next(it), *next(next(it))))
        lines.erase(next(it));
    
    while (it != lines.begin() && prev(it) != lines.begin() && eraseMid(*prev(prev(it)), *prev(it), *it))
        lines.erase(prev(it));
}

double getMin(double x)
{
#if 0
    double real_min = 1e18;
    for (auto it: all_lines)
        real_min = min(real_min, it.eval(x));
#endif
    
    line special = { -1, x };
    auto it = lines.lower_bound(special);
#if 0
    printf("real min %f got %f\n", real_min, it->eval(x));
    if (abs(it->eval(x) - real_min) > 1e-6)
    {
        printf("point %f\n", x);
        for (auto it: lines)
            printf("%f %f\n", it.a, it.b);
    }
    assert(abs(it->eval(x) - real_min) < 1e-6);
#endif
    return it->eval(x);
}

struct guy
{
    int x, v;
};

int s;

vector<double> getTimes(vector<guy> guys)
{
    lines.clear();
    all_lines.clear();
    
    double base = 1e18;
    vector<vector<double>> addSpeeds(MAX + 1);
    for (auto g: guys)
    {
        addSpeeds[g.x].push_back(g.v);
        base = min(base, g.x / (double)g.v);
    }
    
    addLine(line { 0, base });
    
    vector<double> answer(MAX + 1);
    for (int i = 0; i <= MAX; i++)
    {
        for (double v: addSpeeds[i])
            addLine(line { s / ((double)(s + v) * (s - v)), -i * (double)v / (s + v) / (s - v) });
        
        answer[i] = getMin(i);
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n >> s;
    
    vector<guy> left, right;
    for (int i = 0; i < n; i++)
    {
        int x, v, dir;
        cin >> x >> v >> dir;
        
        if (dir == 1)
            left.push_back(guy { x, v });
        else
            right.push_back(guy { MAX - x, v });
    }
    
    vector<double> a = getTimes(left);
    vector<double> b = getTimes(right);
    reverse(all(b));
    
    double answer = 1e18;
    int bestPt = 0;
    for (int i = 0; i <= MAX; i++)
    {
        if (answer > max(a[i], b[i]))
        {
            answer = max(a[i], b[i]);
            bestPt = i;
        }
    }
    
    //printf("best point %d with times %f %f\n", bestPt, a[bestPt], b[bestPt]);
    
    cout << fixed << setprecision(12) << answer << endl;
    
    return 0;
}