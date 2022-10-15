#include <cstdio>

using namespace std;

int read()
{
    const int MAXL = 1000;
    char s[MAXL];
    gets(s);
    int res = 0;
    for (int i = 0; s[i]; i++)
        res += 
            s[i] == 'a' ||
            s[i] == 'e' ||
            s[i] == 'i' ||
            s[i] == 'o' ||
            s[i] == 'u';
    return res;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    puts(read() == 5 && read() == 7 && read() == 5? "YES" : "NO");
    return 0;
}