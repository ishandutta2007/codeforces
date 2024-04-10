#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
/*
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 1000005, INF = 1e18;

int n;
int a[N], b[N];

stack < int > S;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf ("%lld", &a[i]);
    a[0] = INF;
    for (int i = 1; i <= n; i++){
        b[i] = a[i-1] + 1 - a[i];
    }
    for (int i = 2; i <= n; i++){
        if (b[i-1])
            S.push (i-1);
        if (b[i] >= 0)
            continue;
        while (b[i] < 0 && S.top() > 1){
            int x = b[S.top()] * (i - S.top() + 1);
            if (x <= -b[i]){
                b[i+1] -= b[S.top()] * (i - S.top());
                b[i] += x;
                b[S.top()] = 0;
                S.pop();
            }
            else
                break;
        }
        if (b[i] >= 0)
            continue;
        int d = i - S.top() + 1;
        int x = (-b[i]) / d;
        b[i] += x * d;
        b[i+1] -= x * (d-1);
        b[S.top()] -= x;
        int ind = S.top();
        ind += -b[i];
        b[i+1] += b[i];
        b[i] = 0;
        b[ind]++;
        b[S.top()]--;
        if (b[S.top()] == 0)
            S.pop();
        if (ind < i)
            S.push (ind);
    }
    for (int i = 1; i <= n; i++){
        a[i] = a[i-1] + 1 - b[i];
        printf ("%lld ", a[i]);
    }
}