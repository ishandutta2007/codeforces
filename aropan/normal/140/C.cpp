#include <cstdio>
#include <map>
#include <queue>

using namespace std;


map <int, int> M;
priority_queue < pair <int, int> > H;
vector < pair < pair <int, int >, int > > a;
int n;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        M[x]++;
    }

    for (map <int, int> :: iterator iter = M.begin(); iter != M.end(); ++iter)
        H.push(make_pair(iter->second, iter->first));

    while (H.size() > 2)
    {
        pair <int, int> x[3];
        for (int i = 0; i < 3; i++)
        {
            x[i] = H.top();
            H.pop();
        }

        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++)
                if (x[i].second < x[j].second)
                    swap(x[i], x[j]);


        a.push_back(make_pair(make_pair(x[0].second, x[1].second), x[2].second));

        for (int i = 0; i < 3; i++)
        {
            x[i].first--;
            if (x[i].first)
                H.push(x[i]);
        }
    }

    printf("%d\n", a.size());
    for (int i = 0; i < a.size(); i++)
        printf("%d %d %d\n", a[i].first.first, a[i].first.second, a[i].second);
    return 0;
}