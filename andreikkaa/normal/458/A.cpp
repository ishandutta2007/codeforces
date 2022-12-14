#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<long long, long long> > p;
const double q = 1.618033988749895;

void pow()
{
    p.push_back(make_pair(0, 1));
    p.push_back(make_pair(1, 0));
    for(int i = 2; i <= 1e+5 + 10; i++)
    {
        p.push_back(make_pair(p[i - 1].first + p[i - 2].first, p[i - 1].second + p[i - 2].second));
    }
}

int main()
{
    string aa, bb;
    cin >> aa >> bb;
    vector<long long> a, b;

    reverse(aa.begin(), aa.end());
    reverse(bb.begin(), bb.end());
    for(int i = 0; i < aa.length(); i++)
        a.push_back(aa[i] - '0');
    for(int i = 0; i < bb.length(); i++)
        b.push_back(bb[i] - '0');
    while(a.size() < b.size())
        a.push_back(0);
    while(a.size() > b.size())
        b.push_back(0);

    for(int i = a.size() - 1; i >= 2; i--)
    {
        long long m = min(a[i], b[i]);
        a[i] -= m; b[i] -= m;
        if(a[i] == b[i])
            continue;
        if(a[i])
        {
            m = min(a[i], b[i - 1]);
            a[i - 2] += m;
            a[i] -= m;
            b[i - 1] -= m;
            if(a[i])
            {
                if(a[i] > b[i - 2])
                {
                    cout << ">";
                    return 0;
                }
                else
                {
                    a[i - 1] += a[i];
                    a[i - 2] += a[i];
                    a[i] = 0;
                }
            }
        }
        if(b[i])
        {
            m = min(b[i], a[i - 1]);
            b[i - 2] += m;
            b[i] -= m;
            a[i - 1] -= m;
            if(b[i])
            {
                if(b[i] > a[i - 2])
                {
                    cout << "<";
                    return 0;
                }
                else
                {
                    b[i - 1] += b[i];
                    b[i - 2] += b[i];
                    b[i] = 0;
                }
            }
        }
    }
    //cout << a[0] << " " << a[1] << " " << b[0] << " " << b[1];
    if(a.size() == 1)
        cout << (a[0] > b[0] ? ">" : (a[0] == b[0] ? "=" : "<"));
    else
    {
        long long m = min(a[0], b[0]);
        a[0] -= m;
        b[0] -= m;
        m = min(a[1], b[1]);
        a[1] -= m;
        b[1] -= m;
        double r = q * (a[1] - b[1]) + (a[0] - b[0]);
        cout << (r > 0 ? ">" : (r == 0 ? "=" : "<"));
    }
    return 0;
}