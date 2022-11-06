#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const int maxN = 100011;

int n;
pair<int, int> v[maxN];
vector< pair<int, int> > answer;
vector<int> order;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i].first);
        v[i].second = i + 1;
    }

    sort(v, v + n);
    reverse(v, v + n);

    for (int i = 0; i < n; i++)
        order.pb(v[i].second * 2);

    for (int i = 0; i + 1 < n; i++) 
        answer.pb(mp(order[i], order[i + 1]));

    for (int i = 0; i < n; i++) {
        int aux = v[i].first - 1;

        answer.pb(mp(v[i].second * 2 - 1, order[i + aux]));
        if (i + aux + 1 == order.size())
            order.pb(v[i].second * 2 - 1);
    }

    for (auto e : answer)
        printf("%d %d\n", e.first, e.second);


    return 0;
}