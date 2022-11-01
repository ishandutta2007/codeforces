#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long ll;
typedef double ld;

struct tnode
{
    int num;
    int po;
};

tnode a[10000000];

bool cmp(tnode a, tnode b)
{
    return a.po < b.po;
}

vector <int> edges[1000001];
int curpow[1000001];
int current[1000001];

vector <int> uans;
vector <int> vans;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    ll k;
    bool er = false;
    cin >> n >> k;

    for(int i = 1; i < 10 * n; i++)
        curpow[i] = 1;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i].po;
        a[i].num = i;
    }
    sort(a, a + n, cmp);
    if(a[0].po != 0)
        er = true;
    if(a[1].po == 0)
        er = true;

    for(int i = 0; i < n; i++)
    {
        if(a[i].po == 0)
        {
            edges[0].push_back(i);
        }
        else
        {
            if(edges[a[i].po - 1].size() > 0)
            {
                curpow[a[i].po - 1]++;
                //curpow[a[i].po]++;
                uans.push_back(a[i].num);
                vans.push_back(a[edges[a[i].po - 1][0]].num);
            }
            else
                er = true;
            edges[a[i].po].push_back(i);
            if(edges[a[i].po - 1].size() > 0)
            {
            if(curpow[a[i].po - 1] > k && edges[a[i].po - 1].size() == 1)
                er = true;
            if(curpow[a[i].po - 1] >= k)
            {
                curpow[a[i].po - 1] = 1;
                edges[a[i].po - 1].erase(edges[a[i].po - 1].begin());
            }
            }
        }
    }
    if(er)
        cout << -1;
    else
    {
    cout << uans.size() << endl;
    for(int i = 0; i < uans.size(); i++)
        cout << uans[i] + 1 << " " << vans[i] + 1<< endl;
    }
    return 0;
}