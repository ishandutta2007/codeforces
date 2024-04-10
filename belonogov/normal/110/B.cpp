#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
/*
bool ch(int a)
{
    while (a > 0)
    {
        if (a % 10 != 4 && a % 10 != 7)
            return false;
        a /= 10;
    }
    return true;
}
int n, kol = 0, a[1000], uk = 0;
char s[100010];
bool use[100010];

void dfs(int v)
{
    int i;
    use[v] = true;
    s[v] = 'a' + uk;
    for (i = 0; i < n; i++)
    {
        if (v + a[i] < n && ! use[v + a[i]])
        {
            dfs(v + a[i]);
        }
    }
}
*/

int main()
{
 //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
  /*  int i;
    cin >> n;
    for (i = 0; i < n; i++)
        if (ch(i))
        {
            a[kol] = i;
            kol++;
        }
    for (i = 0; i < n; i++)
        use[i] = false;
    for (i = 0; i < n; i++)
    {
        if (! use[i])
            dfs(i);
        uk++;
    }
    for (i = 0; i < n; i++)
        cout << s[i];
*/
    int n, kol, i;
    cin >>n;
    string s = "";
    kol = n / 4 + 1;
    for (i = 0; i < kol; i++)
        s += "abcd";
    for (i = 0; i < n; i++)
        cout << s[i];

/*
    string s = "";
    cin >> n;
    kol = n / 7 + 10;
    for (i = 0; i < kol; i++)
        s +="abcdabc";
    for (i = 0; i < n; i++)
        cout << s[i];



*/

    return 0;
}