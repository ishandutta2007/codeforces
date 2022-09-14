#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

const int INF = 2e9 + 10;

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i)
        cin >> a[i];

    vector<int> used(n);

    int cur = 0;
    for (int i = 0; i < k; ++i) {
        int x = a[i] % (n - i);
        int cnt = 0;
        for (; used[cur]; cur = (cur + 1) % n);

        while (cnt < x) {
            cur = (cur + 1) % n;
            if (!used[cur]) {
                ++cnt;
            }
        }
            
        used[cur] = 1;
        cout << cur + 1 << " ";
    }
    cout << endl;
}