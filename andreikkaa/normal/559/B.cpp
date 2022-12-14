#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 200 * 1000 + 1;

char s[MAX_LEN];
char t[MAX_LEN];

bool f(int a, int b, int c, int d)
{
    if(b - a == 1)
    {
        return s[a] == t[c];
    }

    if((b - a) & 1 == 1)
    {
        return equal(s + a, s + b, t + c);
    }
    
    return 
    (f(a, (a + b) / 2, c, (c + d) / 2) and f((a + b) / 2, b, (c + d) / 2, d))
    or
    (f(a, (a + b) / 2, (c + d) / 2, d) and f((a + b) / 2, b, c, (c + d) / 2));
}


int main()
{
    scanf("%s", s);
    scanf("%s", t);
    
    if(f(0, strlen(s), 0, strlen(t)))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}