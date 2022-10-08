#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct rect{
    int x1, y1, x2, y2;

    bool exists()
    {
        return x1 <= x2 && y1 <= y2;
    }
};

rect operator * (const rect& a, const rect& b)
{
    return rect{
        std::max(a.x1, b.x1),
        std::max(a.y1, b.y1),
        std::min(a.x2, b.x2),
        std::min(a.y2, b.y2)
    };
}

bool try_without(const vector<rect>& r, int banned)
{
    rect r0;
    bool initialized = false;

    for (int i = 0; i < r.size(); ++i)
        if (i != banned)
        {
            if (initialized)
            {
                r0 = r0 * r[i];
                if (!r0.exists())
                {
                    return false;
                }
            }
            else
            {
                initialized = true;
                r0 = r[i];
            }
        }

    cout << r0.x1 << " " << r0.y1 << endl;
    return true;
}

int main()
{
    int n;

    cin >> n;

    vector<rect> r(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
    }

    rect r0 = r[0];
    int x1i = 0, y1i = 0, x2i = 0, y2i = 0;
    for (int i = 1; i < n; ++i)
    {
        rect r1 = r0 * r[i];
        if (r1.exists())
        {
            x1i = r[i].x1 > r0.x1? i : x1i;
            y1i = r[i].y1 > r0.y1? i : y1i;
            x2i = r[i].x2 < r0.x2? i : x2i;
            y2i = r[i].y2 < r0.y2? i : y2i;
            r0 = r1;
        }
        else
        {
            try_without(r, x1i) ||
            try_without(r, y1i) ||
            try_without(r, x2i) ||
            try_without(r, y2i) ||
            try_without(r, i);
            return 0;
        }
    }

    cout << r0.x1 << " " << r0.y1 << endl;

    return 0;
}