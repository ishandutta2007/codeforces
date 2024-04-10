#include <cstdio>
#include <string>
#include <queue>

using namespace std;

queue < pair < string, int > > q;
int m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d", &m);
    q.push(make_pair("Sheldon", 1));
    q.push(make_pair("Leonard", 1));
    q.push(make_pair("Penny",  1));
    q.push(make_pair("Rajesh", 1));
    q.push(make_pair("Howard", 1));
    while (q.size())
    {
        string s = q.front().first;
        int x = q.front().second;
        q.pop();
        m -= x;
        if (m <= 0)
        {
            printf("%s\n", s.c_str());
            break;
        }
        q.push(make_pair(s, x << 1));
    }
    return 0;
}