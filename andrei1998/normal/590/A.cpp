#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int NMAX = 500005;

bool sir[NMAX];

vector <pair <bool, int> > v;
vector <pair <int, int> > v_dir;
vector <int> poss;

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> sir[i];

    v.push_back(make_pair(sir[1], 1));
    v_dir.push_back(make_pair(1, 1));

    for (int i = 2; i <= n; ++ i)
        if (sir[i] == sir[i - 1]) {
            v.back().second ++;
            v_dir.back().second ++;
        }
        else {
            v.push_back(make_pair(sir[i], 1));
            v_dir.push_back(make_pair(i, i));
        }

    poss.push_back(0);
    for (int i = 1; i + 1 < v.size(); ++ i)
        if (v[i].second > 1)
            poss.push_back(i);

    poss.push_back(v.size() - 1);

    int ans = 0;
    int st, dr, l, j;
    for (int i = 1; i < poss.size(); ++ i) {
        st = v_dir[poss[i - 1]].second;
        dr = v_dir[poss[i]].first;
        l = dr - st + 1;

        if (l <= 2)
            continue;

        //cout << "interval " << st << ' ' << dr << endl;

        if ((l - 1) / 2 > ans)
            ans = (l - 1) / 2;

        //Reparam intervalul
        if (sir[st] == sir[dr]) {
            for (j = st + 1; j <= dr; ++ j)
                sir[j] = sir[st];
        }
        else {
            for (j = st; j <= (st + dr) / 2; ++ j)
                sir[j] = sir[st];
            for (j = (st + dr) / 2 + 1; j <= dr; ++ j)
                sir[j] = sir[dr];
        }
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; ++ i)
        cout << sir[i] << " \n"[i == n];
    return 0;
}