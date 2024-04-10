/*
 * Author: code6
 * Created Time:  2012/5/10 23:32:12
 * File Name: A.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-11;

int dp[10000];

void update(int &a, int b)
{
    a = max(a, b);
}

int main() {
    int n, a, b, c;
    int i;
    cin>>n>>a>>b>>c;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (i = 0; i <= n; i++) {
        if (dp[i] != -1) {
            update(dp[i + a],  dp[i] + 1);
            update(dp[i + b],  dp[i] + 1);
            update(dp[i + c],  dp[i] + 1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}