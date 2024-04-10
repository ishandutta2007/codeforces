#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    int aa[s1.length() * s2.length() + 1];
    int bb[s1.length() * s2.length() + 1];
    int aaa = 0, bbb = 0, now = 0;
    aa[now] = bb[now] = 0;
    while (now < s1.length() * s2.length()) {
        int a, b, i = now % s1.length(), j = now % s2.length();
        if (s1[i] == 'R') a = 0;
        if (s1[i] == 'P') a = 1;
        if (s1[i] == 'S') a = 2;
        if (s2[j] == 'R') b = 0;
        if (s2[j] == 'P') b = 1;
        if (s2[j] == 'S') b = 2;
        if ((b - a) % 3 == 1 or (b - a) % 3 == -2) aaa++;
        if ((b - a) % 3 == 2 or (b - a) % 3 == -1) bbb++;
        now++;
        aa[now] = aaa;
        bb[now] = bbb;
    }
    int ans1 = 0, ans2 = 0;
    ans1 += (aa[s1.length() * s2.length()]) * (n / (s1.length() * s2.length()));
    ans2 += (bb[s1.length() * s2.length()]) * (n / (s1.length() * s2.length()));
    ans1 += aa[n % (s1.length() * s2.length())];
    ans2 += bb[n % (s1.length() * s2.length())];
    cout << ans1 << ' ' << ans2 << endl; 
}