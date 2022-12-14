#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n];
    for(long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<pair<long long, long long> > p;
    p.push_back(make_pair(0, 0));
    long long x = 0, y = 0, max_y = 0, min_y = 0;
    for(long long i = 0; i < n; i++)
    {
        x += a[i];
        y += pow(-1, i) * a[i];

        max_y = max(max_y, y);
        min_y = min(min_y, y);
        p.push_back(make_pair(x, y));

    }

    for(int i = max_y; i >= min_y; i--)
    {
        long long c = 0;
        for(int j = 0; j < x; j++)
        {
            if(p[c + 1].first == j)
                c += 1;
            if(c == n)
                return 0;
            if(j - p[c].first == i - p[c].second - 1 and p[c].second < p[c + 1].second)
                cout << "/";
            else if(j - p[c].first == p[c].second - i and p[c].second > p[c + 1].second)
                cout << "\\";
            else
                cout << " ";
        }
        cout << endl;
    }
    
   
   return 0;
}