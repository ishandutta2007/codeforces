#include <bits/stdc++.h>

#define FOR(it, from, to) for (it = from; it < to; it++)
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vvi vector<vi>
#define vvii vector< vector< pair<int, int> > >
#define in(vec, elem) vec.push_back(elem)
#define mem0(ar) memset(ar, 0, sizeof(ar))
#define mem1(ar) memset(ar, -1, sizeof(ar))
#define mii map<int, int>
#define msi map<string, int>
#define msvi map<string, vector<int, int> >

using namespace std;

long long dig(long long num)
{
    long long digits = 0, cnt = 1;
    for(long long i = 9; num > i; i *= 10) {
        digits += i * cnt;
        cnt++; num -= i;
    }
    return digits + num * cnt;
}

main()
{
    long long n; scanf("%I64d", &n);
    printf("%I64d\n", dig(n));
}