#include <deque>
#include <iostream>

using namespace std;

int main()
{
    deque <pair <int, int> > a;
    int n, m, t;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        pair <int, int> k;
        k.first = t;
        k.second = i + 1;
        a.push_back(k);
    }
    pair <int, int> k;
    while(a.size() > 1)
    {
        k = a[0];
        a.pop_front();
        k.first -= m;
        if(k.first > 0)
            a.push_back(k);
    }
    cout << a[0].second;
}