// Stopped writing: probably overly complex
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct event
{
    int x, y1, y2, t;
};

bool operator< (const event& a, const event& b)
{
    if (a.x < b.x)
    {
        return true;
    }
    if (a.x > b.x)
    {
        return false;
    }
    return a.t > b.t;
}

vector<event> e;

inline void add_event(int x, int y1, int y2, int t)
{
    e.push_back(event{x, y1, y2, t});
}

void add_dr(int cd, int cr, int rd, int rr, int n)
{
    int md = n - cd - rd;
    int mr = n - cr - mr;

    add_event(cr, cd, cd + md, 1);
    add_event(cr + mr, cd, cd + md, -1);
}

void add_d(int cd, int cr, int rd, int rr, int n)
{
    int md = n - cd - rd;

    add_event(cr, cd, cd + md, 1);
    add_event(cr, cd, cd + md, -1);
}

void add_r(int cd, int cr, int rd, int rr, int n)
{
    int mr = n - cr - mr;

    add_event(cr, cd, cd, 1);
    add_event(cr + mr, cd, cd, -1);
}

int main()
{
    ios::sync_with_stdio(false);

    int ct;
    cin >> ct;
    for (int t = 0; t < ct; ++t)
    {
        int n;
        string s;
        cin >> n >> s;

        e.clear();

        int td = 0, tr = 0;
        for (char c : s)
        {
            if (c == 'D')
            {
                ++td;
            }
            else
            {
                ++tr;
            }
        }

        if (td == 0 || tr == 0)
        {
            cout << n << endl;
            continue;
        }

        int cd = 0, cr = 0;
        bool areal = false;
        long long ans = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if (c == 'D')
            {
                ++cd;
            }
            else
            {
                ++cr;
            }
            if (cd == 0 && s[i + 1] == 'R' || cr == 0 && s[i + 1] == 'D')
            {
                ++ans;
            }
            else
            {
                if (!areal)
                {
                    areal = true;
                    ans += (n - td) * (long long)(n - tr);
                }
                else if (c == 'D')
                {
                    ans += n - tr;
                }
                else
                {
                    ans += n - td;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}