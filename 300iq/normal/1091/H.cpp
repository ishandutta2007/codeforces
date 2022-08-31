#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>

using namespace std;

typedef long long ll;

#ifdef ONPC
    mt19937 rnd(228);
#else
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 2e5 + 1;

int gr[N];
bitset <N> good;
bitset <N> dp;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, f;
    cin >> n >> f;
    {
        vector <int> ret;
        double start = clock();
        for (int moves = 2; moves < N; moves++)
        {
            int x = moves;
            int cnt = 0;
            for (int i = 2; i * i <= x; i++)
            {
                while (x % i == 0)
                {
                    cnt++;
                    x /= i;
                }
            }
            if (x != 1) cnt++;
            good[moves] = 0;
            if (cnt <= 2 && moves != f) 
            {
                ret.push_back(moves);
                good[moves] = 1;
            }
        }
        set <int> q;
        for (int i = 0; i < N; i++) q.insert(i);
        int x = 0;
        while (!q.empty())
        {
            dp.reset();
            for (int i : q)
            {
                if (!dp[i])
                {
                    dp |= good << i;
                    gr[i] = x;
                }
            }
            set <int> nq;
            for (int i : q)
            {
                if (dp[i])
                    nq.insert(i);
            }
            q = nq;
            x++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ans ^= gr[b - a - 1] ^ gr[c - b - 1];
    }
    if (!ans)
    {
        cout << "Bob\n";
        cout << "Alice\n";
    }
    else
    {
        cout << "Alice\n";
        cout << "Bob\n";
    }
}