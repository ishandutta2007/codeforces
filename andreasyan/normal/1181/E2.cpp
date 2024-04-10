#include <bits/stdc++.h>
using namespace std;
const int N = 100005, INF = 1000000009;
struct ban
{
    int x1, x2;
    int y1, y2;
};

int n, nn;
ban a[N];

bool sox2(const int& i, const int& j)
{
    return a[i].x2 < a[j].x2;
}
bool soy2(const int& i, const int& j)
{
    return a[i].y2 < a[j].y2;
}
bool sox1(const int& i, const int& j)
{
    return a[i].x1 > a[j].x1;
}
bool soy1(const int& i, const int& j)
{
    return a[i].y1 > a[j].y1;
}

struct ban1
{
    int l, r;
    int x;
    ban1(){}
    ban1(int l, int r, int x)
    {
        this->l = l;
        this->r = r;
        this->x = x;
    }
};

bool solv(vector<int> v)
{
    int n = v.size();
    if (n == 1)
        return true;
    vector<int> vx1 = v;
    vector<int> vy1 = v;
    vector<int> vx2 = v;
    vector<int> vy2 = v;
    sort(vx1.begin(), vx1.end(), sox1);
    sort(vy1.begin(), vy1.end(), soy1);
    sort(vx2.begin(), vx2.end(), sox2);
    sort(vy2.begin(), vy2.end(), soy2);
    vector<ban1> tx1(n + 2);
    tx1[0] = ban1(-1, 1, 0);
    tx1[n + 1] = ban1(n, -1, 0);
    for(int i = 1; i <= n; ++i)
        tx1[i] = ban1(i - 1, i + 1, vx1[i - 1]);
    vector<ban1> ty1(n + 2);
    ty1[0] = ban1(-1, 1, 0);
    ty1[n + 1] = ban1(n, -1, 0);
    for(int i = 1; i <= n; ++i)
        ty1[i] = ban1(i - 1, i + 1, vy1[i - 1]);
    vector<ban1> tx2(n + 2);
    tx2[0] = ban1(-1, 1, 0);
    tx2[n + 1] = ban1(n, -1, 0);
    for(int i = 1; i <= n; ++i)
        tx2[i] = ban1(i - 1, i + 1, vx2[i - 1]);
    vector<ban1> ty2(n + 2);
    ty2[0] = ban1(-1, 1, 0);
    ty2[n + 1] = ban1(n, -1, 0);
    for(int i = 1; i <= n; ++i)
        ty2[i] = ban1(i - 1, i + 1, vy2[i - 1]);
    map<int, int> rpx1;
    for (int i = 0; i < vx1.size(); ++i)
        rpx1[vx1[i]] = i + 1;
    map<int, int> rpy1;
    for (int i = 0; i < vy1.size(); ++i)
        rpy1[vy1[i]] = i + 1;
    map<int, int> rpx2;
    for (int i = 0; i < vx2.size(); ++i)
        rpx2[vx2[i]] = i + 1;
    map<int, int> rpy2;
    for (int i = 0; i < vy2.size(); ++i)
        rpy2[vy2[i]] = i + 1;
    int m = n + 1;
    while (1)
    {
        if (n == 1)
            return true;
        int px1 = m, mx1 = -INF;
        int py1 = m, my1 = -INF;
        int px2 = m, mx2 = INF;
        int py2 = m, my2 = INF;
        vector<int> vvx1, vvy1, vvx2, vvy2;
        vector<int> vv;
        for (int i = 0; i < n / 2; ++i)
        {
            px1 = tx1[px1].l;
            mx1 = max(mx1, a[tx1[px1].x].x2);
            vvx1.push_back(tx1[px1].x);
            if (mx1 <= a[tx1[tx1[px1].l].x].x1)
            {
                vv = vvx1;
                break;
            }
            py1 = ty1[py1].l;
            my1 = max(my1, a[ty1[py1].x].y2);
            vvy1.push_back(ty1[py1].x);
            if (my1 <= a[ty1[ty1[py1].l].x].y1)
            {
                vv = vvy1;
                break;
            }
            px2 = tx2[px2].l;
            mx2 = min(mx2, a[tx2[px2].x].x1);
            vvx2.push_back(tx2[px2].x);
            if (a[tx2[tx2[px2].l].x].x2 <= mx2)
            {
                vv = vvx2;
                break;
            }
            py2 = ty2[py2].l;
            my2 = min(my2, a[ty2[py2].x].y1);
            vvy2.push_back(ty2[py2].x);
            if (a[ty2[ty2[py2].l].x].y2 <= my2)
            {
                vv = vvy2;
                break;
            }
        }
        if (vv.empty())
            return false;
        n -= vv.size();
        for (int i = 0; i < vv.size(); ++i)
        {
            int x = vv[i];
            tx1[tx1[rpx1[x]].r].l = tx1[rpx1[x]].l;
            tx1[tx1[rpx1[x]].l].r = tx1[rpx1[x]].r;
            ty1[ty1[rpy1[x]].r].l = ty1[rpy1[x]].l;
            ty1[ty1[rpy1[x]].l].r = ty1[rpy1[x]].r;
            tx2[tx2[rpx2[x]].r].l = tx2[rpx2[x]].l;
            tx2[tx2[rpx2[x]].l].r = tx2[rpx2[x]].r;
            ty2[ty2[rpy2[x]].r].l = ty2[rpy2[x]].l;
            ty2[ty2[rpy2[x]].l].r = ty2[rpy2[x]].r;
        }
        if (solv(vv) == false)
            return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    nn = n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    if (solv(v))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}